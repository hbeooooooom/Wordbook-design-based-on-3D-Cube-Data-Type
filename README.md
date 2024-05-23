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
