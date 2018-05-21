class ring:
    _value = 0
    _name = ''
    def __init__(self, n, ringName):
        self._value = n
        self._name = ringName
    def __str__(self):
        return '{} value {}'.format(self._name, self._value)


def move(m, origin, goal, support):
    for n in range(1, m+1):
        support.append(origin.pop())
        if n > 1:
            move(n-1, goal, origin, support)
        goal.append(support.pop())
        if n > 1:
            move(n-1, origin, goal, support)
        
        
origin = []
support = []
goal = []


if __name__ == '__main__':

    ring1 = ring(1, 'ring1');
    ring2 = ring(2, 'ring2');
    ring3 = ring(3, 'ring3');
    ring4 = ring(4, 'ring4');
    ring5 = ring(5, 'ring5');
    ring6 = ring(6, 'ring6');

    origin.append(ring1)
    origin.append(ring2)
    origin.append(ring3)
    origin.append(ring4)
    origin.append(ring5)
    origin.append(ring6)

    print('rings in origin before the move')
    for ringEl in origin:
        print(ringEl)

    move(len(origin), origin, goal, support)

    print('rings in origin')
    for ringEl in origin:
        print(ringEl)
    print('rings in support')
    for ringEl in support:
        print(ringEl)
    print('rings in goal')
    for ringEl in goal:
        print(ringEl)
