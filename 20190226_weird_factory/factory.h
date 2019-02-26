#pragma once

#include <memory>
#include <list>
#include <map>


class BaseModelNode {};


enum class ModelIDs : int {
  FooModelID = 0
};


class BaseReader;
class FileReader
{
  public:
    FileReader() = default;
    virtual ~FileReader() = default;
    std::shared_ptr<BaseReader> getNodeReader(ModelIDs id);
    ModelIDs getModelID(const char* pFileDoc);
    char read() {};
    
  private:
    std::map<ModelIDs, std::shared_ptr<BaseReader>> readerMap;
};


class BaseReader
{
  public:
    virtual std::list<BaseModelNode *> read() = 0;
    void setFileReader(FileReader *pFileReader);

  protected:
    FileReader *pFileReader{nullptr};
};


class BaseReaderFactory
{
  protected:
    BaseReaderFactory(std::initializer_list<ModelIDs> ids);
    virtual ~BaseReaderFactory() = default;

  public:
    virtual std::shared_ptr<BaseReader> createModelReader(FileReader *pModelReader) = 0;
};


#define MAP_READER_TO_TYPES(READER, ...)				                   \
    class READER##Factory : BaseReaderFactory                                              \
    {                                                                                      \
        static READER##Factory instance;                                                   \
                                                                                           \
        READER##Factory() noexcept : BaseReaderFactory({__VA_ARGS__}) {}                   \
                                                                                           \
    public:                                                                                \
        ~READER##Factory();                                                                \
        std::shared_ptr<BaseReader> createModelReader(FileReader *pModelReader)            \
        {                                                                                  \
            auto pModelIdReader = READER::create();                                        \
            pModelIdReader->setFileReader(pModelReader);                                   \
            return std::dynamic_pointer_cast<BaseReader>(pModelIdReader);                  \
        }                                                                                  \
    };


#define MODEL_READER_HELPER(READER)                                                        \
  public:                                                                                  \
    virtual ~READER() = default;                                                           \
    READER()          = default;                                                           \
                                                                                           \
  protected:                                                                               \
    static std::shared_ptr<READER> create()                                                \
    {                                                                                      \
         struct READER_ENABLER : public READER {                                           \
         };						                                   \
	 struct READER_ENABLER reader;					                   \
	 return std::make_shared<READER>(reader);	                                   \
    }                                                                                      \
    friend class READER##Factory;


#define INSTANTIATE_READER_FACTORY(READER)                                                 \
    READER##Factory READER##Factory::instance;                                             \
    READER##Factory::~READER##Factory() {}
