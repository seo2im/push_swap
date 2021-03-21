# Push swap

2개의 Stack과 11개의 명령어를 이용하여 정렬을 구현하는 최적방법을 찾는 문제

## 룰

### 목표
Game에 2개의 `stack`(`a`, `b`)이 존재하고 시작할 때, `a`에 정렬되지 않은 `stack`이 존재하며 아래 명령어를 적절히 실행하여 최종적으로 `a`가 정렬된 `stack`이 되도록 하는것이 목표이다.

### 명령어
- `sa` : `a` 의 최상단 2개 요소의 위치를 변경한다.
- `sb` : `b` 의 최상단 2개 요소의 위치를 변경한다.
- `ss` : `sa`와 `sb`를 동시에 실행한다.

- `pa` : `b`의 최상단 요소를 `a`의 최상단으로 넘긴다.
- `pb` : `a`의 최상단 요소를 `b`의 최상단으로 넘긴다.

- `ra` : `a`의 최상단 요소를 최하단으로 보낸다.
- `rb` : `b`의 최상단 요소를 최하단으로 보낸다.
- `rr` : `ra`와 `rb`를 동시에 실행한다.

- `rra` : `a`의 최하단 요소를 최상단으로 보낸다.
- `rrb` : `b`의 최하단 요소를 최상단으로 보낸다.
- `rrr` : `rra`와 `rrb`를 동시에 실행한다.

## 프로그램 구성
### "checker" 프로그램
**checker**는 `a stack`에 넣을 값을 argument로 받고 실행할 명령을 stdin으로 받아 실행 후 해당 요소가 게임의 목표(정렬된 `a stack`)에 부합하는 지 확인한다.

### "push_swap" 프로그램
**push_swap**은 argument로 `a stack`의 요소를 받고 게임의 최적해를 찾는 프로그램

## 프로그램 구축
### Basic
2개의 `stack`을 가져야 하니 `stack`구조를 구현해 두어야 한다. 2중 연결리스트로 구조화하고 stack이 가져야 할 함수들을 구현한다.
`stack`의 구조는 아래와 같이 요소와 길이를 담고있는 구조내부에 node를 가지고 있는 형태이다.
```cpp
struct Node {
    int value;
    Node *before;
    Node *next
}

struct stack {
    int size;
    Node *node
}
```

각각의 구현된 함수는 stack이 기본적으로 가져야할 함수들을 구현한다. 
 - `empty`: stack이 비었는지 확인한다.
 - `top`: stack의 최상단 node의 값을 반환한다.
 - `push`: stack의 최상단에 요소를 추가한다.
 - `pop`: stack의 최상단 Node를 제거하고 반환한다.
 - `size`: stack의 길이를 반환한다.

위 명령어를 통해 각각의 `exec`들을 구현한다.
**sa / sb**
```cpp
node one = stack.pop()
node two = stack.pop()

stack.push(one)
stack.push(two)
```

**pa / pb**
```cpp
node n = give_stack.pop()
get_stack.push(n);
```

<span style="color:red">**ra / rb / rra / rrb**</span>
위 두 규격은 속도상 pop / push를 이용하는 것 보다 rotate함수를 따로 구현해 두는것이 속도향상에 큰 도움이 된다. 따라서 현 구현은 push / pop을 이용하지 않고 연결 리스트의 회전을 구현해두었다. 따라서 차후 변경을 예정하고 있다.

### Checker

checker는 argument를 통해 stack을 구성하고 stdin을 통해 exec_command를 받아 실행시킨 후 해당 stack이 정렬되었는지 확인한다.
따라서 최소 3개의 logic이 요구된다.

1. argument를 받아 최초의 stack을 구성
    - argument가 숫자가 아닌 경우 error
    - argument가 없는 경우 error
    - argument가 int를 넘으면 error
    - argument가 중복되면 error
2. stdin을 받아 exec을 수행
    - stdin에 정상적인 명령어가 없는 경우 error
    - 명령어 포맷이 정상적이지 않은 경우(\n으로 이뤄지지 않음) error

### Push_swap

이를 해결하기 위한 알고리즘을 구현한다. 일단 가장 간단히 생각할 수 있는 알고리즘은 a에 가장 작은 요소를 위로 올리고 b로 넘기는 동작을 반복한 후 다시 a로 넘기는 과정을 행하면 된다.

```python
def simple (a, b) :
    while a.size != 0 :
        while (all number check) in a :
            if min > a.top()
                ra()
        pb()
    while b.size != 0 :
        pa()
```

위 방법은 절대적으로 성공하지만 전혀 최적화되어있지 않다.