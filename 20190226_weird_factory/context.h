#pragma once

#include "factory.h"
#include <map>


class Context {
 public:
  Context() = default;
  ~Context() = default;
  Context(Context const&) = delete;
  Context(Context const&&) = delete;

  static Context& getInstance() {
    static Context instance;
    return instance;
  }

  void operator=(Context const&) = delete;
  
  void registerReaderFactory(ModelIDs id, BaseReaderFactory* readerFactory) {
    readerFactoryMap[id] = readerFactory;
  }

  BaseReaderFactory* getNodeReaderFactory(ModelIDs id) {
    auto find = readerFactoryMap.find(id);
    
    if (find != readerFactoryMap.end()) {
      return readerFactoryMap[id];
    }

    return nullptr;
  }

 private:
  std::map<ModelIDs, BaseReaderFactory*> readerFactoryMap;
};
