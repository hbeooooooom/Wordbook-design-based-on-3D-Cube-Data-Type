프로젝트는 각 면이 회전할 수 있고 Block끼리 교환할 수 있는 3x3x3크기의 3D 큐브를 구성 
해 큐브 내부에 단어를 저장하는 프로그램의 구현을 목표로 한다. 큐브는 27개의 Block이 3D 
Linked List로 연결되어 Figure 1과 같이 구성되어 있으며 큐브의 각 면은 회전이 가능하다. 
또한 큐브의 각 Block은 내부에 Binary Search Tree(BST)를 가지고 있어 BST를 이용해 단어 
의 저장, 삭제, 탐색, 출력이 가능하다.

![1](https://github.com/hbeooooooom/Wordbook-design-based-on-3D-Cube-Data-Type/blob/main/readmemdpng/1.png)


데이터의    구조
프로젝트는    3D Linked List를    이용해    27개의    Block을    연결하며    27개의    Block은    각각의    내부에 
BST를    가지고    있다.
✓         3D Linked List
3D Linked List는    각    Node가    6개의    방향(상,하,좌,우,앞,뒤)로    연결되어    있는    구조이다. 연 
결이란    각    Node가    가지고    있는    Pointer가    다른   Node를    연결하고    있는    것을    의미한다. 
3D Linked List는    2D Linked List를    쌓아    구성할    수    있으며    2D Linked List는    1D Linked List 
들을    평행하게    펼친    후    연결하는    방법으로    구성할    수    있다.
Figure 2는    1D Linked List에    대한    그림으로    1D Linked List는    그림과    같이    각각의    Node(그 
림의    사각형)들이   서로    일렬로    연결되어    있는    구조를    말한다. 이    때    Node는    좌, 우의 
Node들을    가리키는    포인터를    가지고    있어   각    Node를    가리킨다.

![2](https://github.com/hbeooooooom/Wordbook-design-based-on-3D-Cube-Data-Type/blob/main/readmemdpng/2.png)

Figure3은 1D Linked List를 평행하게 펼친 후 서로 연결해 2D Linked List를 구성한 모습 
이다. 2D Linked List는 1D Linked List의 Node들이 서로 상,하로 연결되는 구조로 구성되며 
2D Linked List의 각 Node들은 상,하,좌,우의 Node들을 가리키는 4개의 포인터를 가지고 
있다.

![3](https://github.com/hbeooooooom/Wordbook-design-based-on-3D-Cube-Data-Type/blob/main/readmemdpng/3.png)

Figure4는    2D Linked List를    쌓은    후    서로    연결해    3D Linked List를    구성한    모습이다. 3D 
Linked List는    2D Linked List의    Node들이   서로    앞, 뒤로    연결되는    구조로    구성되며    3D 
Linked List의    각    Node들은    상,하,좌,우,앞,뒤의   Node들을    가리키는    6개의    포인터를    가지 
고    있다.

![4](https://github.com/hbeooooooom/Wordbook-design-based-on-3D-Cube-Data-Type/blob/main/readmemdpng/4.png)

✓         Binary Search Tree
Binary Search Tree는 한 개의 Node가 2개의 Child Node를 가지는 구조로 이루어진 자료 
구조이다. Node의 Child Node는 각각 Left, Right로 분류하며 Left는 Node보다 작은 값의 
Node를, Right는 Node보다 큰 값의 Node를 Child로 가진다.
BST는    Node를    삽입    시    최초의    Root Node부터   시작해    Node보다    작으면    Left,  크면 
Right Child로    이동하며    다음   Node의    설치    장소를    찾으며    나아갈    방향에    Child Node가없을    경우    그    자리에    삽입된다.
또한    BST는    Node  삭제    시    BST의    구조를    그대로    유지해야    하므로    아래    3가지   경우를 
고려해서    Node를    삭제한다.
➢         Child가    없는   Node의    경우: Node만    삭제
➢         Child가    1개인    Node의    경우: Child Node를    삭제할    Node의    Parent와    연결    후 
Node를    삭제
➢         Child가    2개인    Node의    경우: 삭제할    Node의    우측   Subtree  중    가장    왼쪽의 
Node와    Node의    값을    바꾸고    Subtree의    가장    왼쪽    Node를    제거

⚫          프로젝트의    구성
프로젝트는 3개의 Problem으로 구성되어 있으며 3가지 Problem을 합쳐 하나의 프로젝트를 
구성하며 EXIT  명령을 받기 전까지 Command를 입력 받아 동작한다. 세부 배점은 채점기준 
참고

프로젝트 시작 시 3x3x3  크기의 3D Linked List로 구성되어있는 3D 큐브를 구성한다. 3D 
큐브의 각 Block은 Figure 4와같이 상,하,좌,우,전,후를 서로 포인터를 이용해 연결되어 있 
으며 큐브의 각 Block은 전면 좌상단을 영점으로 (z,y,x)의 좌표값을 가지고 있다.(Block 
들은 3d Linked List  외 다른 구조로 접근,삭제하지 않는다. Array에 block들을 넣고 저 
장해 사용하거나 하지 않는다)

![5](https://github.com/hbeooooooom/Wordbook-design-based-on-3D-Cube-Data-Type/blob/main/readmemdpng/5.png)

WordBook.txt파일을    읽어   3x3x3 3D 큐브의    각    Block에    저장한다. 각    Block은    하나의 
BST  구조를    가지고    있으며   WordBook.txt은    줄마다    ‘z좌표    y좌표    x좌표    단어’로    구성되어 
있어    (Figure 6 참고) WordBook.txt의    각    줄에   적혀져    있는    z좌표, y좌표, x좌표에   위치한Block의    BST에    단어를    사전식    정렬    순으로    저장한다.

![6](https://github.com/hbeooooooom/Wordbook-design-based-on-3D-Cube-Data-Type/blob/main/readmemdpng/6.png)

프로젝트는    3D Cube와    BST에    대해서    Table 1의    Insert, Delete, Find, Print, Print_All  명령어를 
수행할    수    있어야    한다. (모든    명령어에서    단어의    대,소문자는    구별하지    않는다)



3D 큐브를    Turn 명령어에    따라    각    면을    회전시키고    Exchange  명령어에    따라서   Block의    위 
치를    교환한다. Turn은    Table 1에서    설명하고    있는   바와    같이    전면, 윗면, 측면에    대해서    시계 
방향, 반시계방향으로    면의    회전을    수행해야   하며(Figure 7), Exchange는    2개의   Block의    위치 
를    교환해야    한다. 또한    Turn과    Exchange의    수행   후에도    3D Cube의    모든    Block간    연결은 
올바르게    연결되어    있어야    하며    반복해서    수행해도    오류가    없어야    한다.
