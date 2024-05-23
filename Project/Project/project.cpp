#include<iostream>
#include<fstream>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;
int countaaa = 0;
class BST {
public:
    char data[30] = { NULL };
    BST* right = NULL;
    BST* left = NULL;
};
class cube {
public:
    int x = NULL;
    int y = NULL;
    int z = NULL;
    BST* BSTnext = NULL;
    cube* right = NULL;
    cube* left = NULL;
    cube* up = NULL;
    cube* down = NULL;
    cube* front = NULL;
    cube* back = NULL;
    cube* next = NULL; //1차원 큐브
};
class cube_list {
private:
    cube* head = NULL;
    cube* save_cube = NULL;
    BST* BST_currNode = NULL;
public:
    void made_cube();//1차원 큐브 선언 및 3차원으로 연결, 3차원으로 만든 후 사용 X
    cube* find_cube(int x, int y, int z);//좌표에 맞는 큐브 찾기, 1차원에서 3차원으로 연결하는 과정에서 사용, 3차원으로 연결 후 사용 X
    void push_word(int x, int y, int z, char* word);//큐브에 단어 정렬, 1번 insert까지 같이 사용하는 함수
    cube* find_cube_3D(int x, int y, int z);//3차원 연결된 상태에서 큐브의 좌표로 찾아가기 큐브의 좌표를 찾을땐 이 함수 사용
    void delete_word(int x, int y, int z, char* word);//command table 2번 단어삭제
    void print_word(int x, int y, int z);//command 4번
    void preorder_print_word(BST* currword);//전위순회
    void inorder_print_word(BST* currword);//중위순회
    void postorder_print_word(BST* currword);//후위순회
    void find_word(char* word);//command table 3번
    int find_word_BST(BST* currcube, char* word);//좌표마다 단어가 있는지 체크 있으면 1 반환
    int word_count(BST* currword);//print all command 5번의 단어 개수 카운트
    void print_all();//print all command
    void exchange(int x1, int y1, int z1, int x2, int y2, int z2);//command 7번 exchange
    void turn(int A, int B, int C);//turn
    void delete_cube();
    void memoryfree(cube* currcube);
};
void cube_list::memoryfree(cube* currcube) {
    BST* currNode=currcube->BSTnext,*leaf=currNode;
    while (1) {
        while (currcube->BSTnext->left != NULL || currcube->BSTnext->right != NULL) {
            while (1) {
                if (currNode->left != NULL) {
                    leaf = currNode;
                    currNode = currNode->left;
                    if (currNode->left == NULL && currNode->right == NULL) {
                        delete currNode;
                        leaf->left = NULL;
                        break;
                    }
                }
                else if (currNode->right != NULL) {
                    leaf = currNode;
                    currNode = currNode->right;
                    if (currNode->left == NULL && currNode->right == NULL) {
                        delete currNode;
                        leaf->right = NULL;
                        break;
                    }
                }
            }
            currNode = currcube->BSTnext;
        }
        delete currcube->BSTnext;
        break;
    }
}
void cube_list::delete_cube() {
    cube* cube1 = find_cube_3D(0, 0, 0);
    if (cube1->BSTnext != NULL) { memoryfree(cube1); }
    cube* cube2 = find_cube_3D(0, 0, 1);
    if (cube2->BSTnext != NULL) { memoryfree(cube2); }
    cube* cube3 = find_cube_3D(0, 0, 2);
    if (cube3->BSTnext != NULL) { memoryfree(cube3); }
    cube* cube4 = find_cube_3D(0, 1, 0);
    if (cube4->BSTnext != NULL) { memoryfree(cube4); }
    cube* cube5 = find_cube_3D(0, 1, 1);
    if (cube5->BSTnext != NULL) { memoryfree(cube5); }
    cube* cube6 = find_cube_3D(0, 1, 2);
    if (cube6->BSTnext != NULL) { memoryfree(cube6); }
    cube* cube7 = find_cube_3D(0, 2, 0);
    if (cube7->BSTnext != NULL) { memoryfree(cube7); }
    cube* cube8 = find_cube_3D(0, 2, 1);
    if (cube8->BSTnext != NULL) { memoryfree(cube8); }
    cube* cube9 = find_cube_3D(0, 2, 2);
    if (cube9->BSTnext != NULL) { memoryfree(cube9); }
    cube* cube10 = find_cube_3D(1, 0, 0);
    if (cube10->BSTnext != NULL) { memoryfree(cube10); }
    cube* cube11 = find_cube_3D(1, 0, 1);
    if (cube11->BSTnext != NULL) { memoryfree(cube11); }
    cube* cube12 = find_cube_3D(1, 0, 2);
    if (cube12->BSTnext != NULL) { memoryfree(cube12); }
    cube* cube13 = find_cube_3D(1, 1, 0);
    if (cube13->BSTnext != NULL) { memoryfree(cube13); }
    cube* cube14 = find_cube_3D(1, 1, 1);
    if (cube14->BSTnext != NULL) { memoryfree(cube14); }
    cube* cube15 = find_cube_3D(1, 1, 2);
    if (cube15->BSTnext != NULL) { memoryfree(cube15); }
    cube* cube16 = find_cube_3D(1, 2, 0);
    if (cube16->BSTnext != NULL) { memoryfree(cube16); }
    cube* cube17 = find_cube_3D(1, 2, 1);
    if (cube17->BSTnext != NULL) { memoryfree(cube17); }
    cube* cube18 = find_cube_3D(1, 2, 2);
    if (cube18->BSTnext != NULL) { memoryfree(cube18); }
    cube* cube19 = find_cube_3D(2, 0, 0);
    if (cube19->BSTnext != NULL) { memoryfree(cube19); }
    cube* cube20 = find_cube_3D(2, 0, 1);
    if (cube20->BSTnext != NULL) { memoryfree(cube20); }
    cube* cube21 = find_cube_3D(2, 0, 2);
    if (cube21->BSTnext != NULL) { memoryfree(cube21); }
    cube* cube22 = find_cube_3D(2, 1, 0);
    if (cube22->BSTnext != NULL) { memoryfree(cube22); }
    cube* cube23 = find_cube_3D(2, 1, 1);
    if (cube23->BSTnext != NULL) { memoryfree(cube23); }
    cube* cube24 = find_cube_3D(2, 1, 2);
    if (cube24->BSTnext != NULL) { memoryfree(cube24); }
    cube* cube25 = find_cube_3D(2, 2, 0);
    if (cube25->BSTnext != NULL) { memoryfree(cube25); }
    cube* cube26 = find_cube_3D(2, 2, 1);
    if (cube26->BSTnext != NULL) { memoryfree(cube26); }
    cube* cube27 = find_cube_3D(2, 2, 2);
    if (cube27->BSTnext != NULL) { memoryfree(cube27); }
    delete cube1;
    delete cube2;
    delete cube3;
    delete cube4;
    delete cube5;
    delete cube6;
    delete cube7;
    delete cube8;
    delete cube9;
    delete cube10;
    delete cube11;
    delete cube12;
    delete cube13;
    delete cube14;
    delete cube15;
    delete cube16;
    delete cube17;
    delete cube18;
    delete cube19;
    delete cube20;
    delete cube21;
    delete cube22;
    delete cube23;
    delete cube24;
    delete cube25;
    delete cube26;
    delete cube27;
}
void cube_list::turn(int A, int B, int C) {
    if (A == 0) {
        if (B == 1) {
            exchange(0, C, 0, 0, C, 2);
            exchange(0, C, 1, 1, C, 2);
            exchange(0, C, 0, 2, C, 2);
            exchange(0, C, 1, 2, C, 1);
            exchange(2, C, 0, 0, C, 0);
            exchange(0, C, 1, 1, C, 0);
            print_all();
        }
        else if (B == 0) {
            exchange(0, C, 0, 2, C, 0);
            exchange(1, C, 0, 2, C, 1);
            exchange(0, C, 0, 2, C, 2);
            exchange(1, C, 0, 1, C, 2);
            exchange(0, C, 0, 0, C, 2);
            exchange(1, C, 0, 0, C, 1);
            print_all();
        }
    }
    else if (A == 1) {
        if (B == 1) {
            exchange(2, 0, C, 2, 2, C);
            exchange(2, 1, C, 1, 2, C);
            exchange(2, 0, C, 0, 2, C);
            exchange(2, 0, C, 0, 0, C);
            exchange(2, 1, C, 0, 1, C);
            exchange(1, 0, C, 2, 1, C);       
            print_all();
        }
        else if (B == 0) {
            exchange(2, 0, C, 0, 0, C);
            exchange(1, 0, C, 0, 1, C);
            exchange(2, 0, C, 0, 2, C);
            exchange(2, 0, C, 2, 2, C);
            exchange(1, 0, C, 1, 2, C);
            exchange(2, 1, C, 1, 0, C);
            print_all();
        }
    }
    else if (A == 2) {
        if (B == 1) {
            exchange(C, 0, 2, C, 2, 2);
            exchange(C, 1, 2, C, 2, 1);
            exchange(C, 0, 2, C, 2, 0);
            exchange(C, 1, 2, C, 1, 0);
            exchange(C, 0, 2, C, 0, 0);
            exchange(C, 1, 2, C, 0, 1);
            print_all();
        }
        else if (B == 0) {
            exchange(C, 0, 2, C, 0, 0);
            exchange(C, 0, 1, C, 1, 0);
            exchange(C, 0, 2, C, 2, 0);
            exchange(C, 0, 2, C, 2, 2);
            exchange(C, 0, 1, C, 2, 1);
            exchange(C, 0, 1, C, 1, 2);
            print_all();
        }
    }
}
void cube_list::exchange(int x1, int y1, int z1, int x2, int y2, int z2) {
    cube* currcube1 = find_cube_3D(x1, y1, z1);
    cube* currcube2 = find_cube_3D(x2, y2, z2);
    cube* curr1 = NULL;//가리키는 주소값을 저장해두는 가리키는 용도
    cube* curr2 = NULL;
    cube* curr3 = NULL;
    cube* curr4 = NULL;
    cube* curr5 = NULL;
    cube* curr6 = NULL;
    cube* curr7 = NULL;
    cube* curr8 = NULL;
    cube* curr9 = NULL;
    cube* curr10 = NULL;
    cube* curr11 = NULL;
    cube* curr12 = NULL;
    cube* temp1 = new cube;
    cube* temp2 = new cube;
    if (currcube1->left != NULL) { temp1->left = currcube1->left; }//큐브 1 바꾸는 큐브가 
    if (currcube1->right != NULL) { temp1->right = currcube1->right; }
    if (currcube1->up != NULL) { temp1->up = currcube1->up; }
    if (currcube1->down != NULL) { temp1->down = currcube1->down; }
    if (currcube1->front != NULL) { temp1->front = currcube1->front; }
    if (currcube1->back != NULL) { temp1->back = currcube1->back; }
    if (currcube2->left != NULL) { temp2->left = currcube2->left; }//큐브2
    if (currcube2->right != NULL) { temp2->right = currcube2->right; }
    if (currcube2->up != NULL) { temp2->up = currcube2->up; }
    if (currcube2->down != NULL) { temp2->down = currcube2->down; }
    if (currcube2->front != NULL) { temp2->front = currcube2->front; }
    if (currcube2->back != NULL) { temp2->back = currcube2->back; }//가르키는 주소값들을 저장

    if (x1 == 0) {//큐브 1을 가리키는 큐브들 저장
        curr1 = find_cube_3D(x1 + 1, y1, z1);
    }
    else if (x1 == 1) {
        curr4 = find_cube_3D(x1 - 1, y1, z1);
        curr1 = find_cube_3D(x1 + 1, y1, z1);
    }
    else if (x1 == 2) {
        curr4 = find_cube_3D(x1 - 1, y1, z1);
    }
    if (y1 == 0) {
        curr2 = find_cube_3D(x1, y1 + 1, z1);
    }
    else if (y1 == 1) {
        curr2 = find_cube_3D(x1, y1 + 1, z1);
        curr5 = find_cube_3D(x1, y1 - 1, z1);
    }
    else if (y1 == 2) {
        curr5 = find_cube_3D(x1, y1 - 1, z1);
    }
    if (z1 == 0) {
        curr3 = find_cube_3D(x1, y1, z1 + 1);
    }
    else if (z1 == 1) {
        curr3 = find_cube_3D(x1, y1, z1 + 1);
        curr6 = find_cube_3D(x1, y1, z1 - 1);
    }
    else if (z1 == 2) {
        curr6 = find_cube_3D(x1, y1, z1 - 1);
    }

    if (x2 == 0) {//큐브2를 가리키는 큐브들 저장
        curr7 = find_cube_3D(x2 + 1, y2, z2);
    }
    else if (x2 == 1) {
        curr10 = find_cube_3D(x2 - 1, y2, z2);
        curr7 = find_cube_3D(x2 + 1, y2, z2);
    }
    else if (x2 == 2) {
        curr7 = find_cube_3D(x2 - 1, y2, z2);
    }
    if (y2 == 0) {
        curr8 = find_cube_3D(x2, y2 + 1, z2);
    }
    else if (y2 == 1) {
        curr8 = find_cube_3D(x2, y2 + 1, z2);
        curr11 = find_cube_3D(x2, y2 - 1, z2);
    }
    else if (y2 == 2) {
        curr11 = find_cube_3D(x2, y2 - 1, z2);
    }
    if (z2 == 0) {
        curr9 = find_cube_3D(x2, y2, z2 + 1);
    }
    else if (z2 == 1) {
        curr9 = find_cube_3D(x2, y2, z2 + 1);
        curr12 = find_cube_3D(x2, y2, z2 - 1);
    }
    else if (z2 == 2) {
        curr12 = find_cube_3D(x2, y2, z2 - 1);
    }

    if (x1 == 0) {//위에서 저장한 큐브들 주소값 변경
        curr1->up = currcube2;
    }
    else if (x1 == 1) {
        curr4->down = currcube2;
        curr1->up = currcube2;
    }
    else if (x1 == 2) {
        curr4->down = currcube2;
    }
    if (y1 == 0) {
        curr2->left = currcube2;
    }
    else if (y1 == 1) {
        curr2->left = currcube2;
        curr5->right = currcube2;
    }
    else if (y1 == 2) {
        curr5->right = currcube2;
    }
    if (z1 == 0) {
        curr3->front = currcube2;
    }
    else if (z1 == 1) {
        curr3->front = currcube2;
        curr6->back = currcube2;
    }
    else if (z1 == 2) {
        curr6->back = currcube2;
    }
    if (x2 == 0) {//큐브2
        curr7->up = currcube1;
    }
    else if (x2 == 1) {
        curr10->down = currcube1;
        curr7->up = currcube1;
    }
    else if (x2 == 2) {
        curr7->down = currcube1;
    }
    if (y2 == 0) {
        curr8->left = currcube1;
    }
    else if (y2 == 1) {
        curr8->left = currcube1;
        curr11->right = currcube1;
    }
    else if (y2 == 2) {
        curr11->right = currcube1;
    }
    if (z2 == 0) {
        curr9->front = currcube1;
    }
    else if (z2 == 1) {
        curr9->front = currcube1;
        curr12->back = currcube1;
    }
    else if (z2 == 2) {
        curr12->back = currcube1;
    }

    currcube1->x = x2;
    currcube1->y = y2;//좌표값 변경
    currcube1->z = z2;
    currcube2->x = x1;
    currcube2->y = y1;
    currcube2->z = z1;

    if (temp2->right != NULL) { currcube1->right = temp2->right; }//큐브 1,2가 가리키는 주소들 초기화 및 주소 정해주기
    else if (temp2->right == NULL) { currcube1->right = NULL; }
    if (temp2->left != NULL) { currcube1->left = temp2->left; }
    else if (temp2->left == NULL) { currcube1->left = NULL; }
    if (temp2->front != NULL) { currcube1->front = temp2->front; }
    else if (temp2->front == NULL) { currcube1->front = NULL; }
    if (temp2->back != NULL) { currcube1->back = temp2->back; }
    else if (temp2->back == NULL) { currcube1->back = NULL; }
    if (temp2->up != NULL) { currcube1->up = temp2->up; }
    else if (temp2->up == NULL) { currcube1->up = NULL; }
    if (temp2->down != NULL) { currcube1->down = temp2->down; }
    else if (temp2->down == NULL) { currcube1->down = NULL; }
    if (temp1->right != NULL) { currcube2->right = temp1->right; }
    else if (temp1->right == NULL) { currcube2->right = NULL; }
    if (temp1->left != NULL) { currcube2->left = temp1->left; }
    else if (temp1->left == NULL) { currcube2->left = NULL; }
    if (temp1->front != NULL) { currcube2->front = temp1->front; }
    else if (temp1->front == NULL) { currcube2->front = NULL; }
    if (temp1->back != NULL) { currcube2->back = temp1->back; }
    else if (temp1->back == NULL) { currcube2->back = NULL; }
    if (temp1->up != NULL) { currcube2->up = temp1->up; }
    else if (temp1->up == NULL) { currcube2->up = NULL; }
    if (temp1->down != NULL) { currcube2->down = temp1->down; }
    else if (temp1->down == NULL) { currcube2->down = NULL; }

    if (x1 == 0 && y1 == 0 && z1 == 0) {//000이면 헤드값 변경
        head = currcube2;
    }
    else if (x2 == 0 && y2 == 0 && z2 == 0) {
        head = currcube1;
    }
    delete temp1;
    delete temp2;
    return;
}
int cube_list::word_count(BST* currword) {
    if (currword != NULL) {
        countaaa++;
        word_count(currword->left);
        word_count(currword->right);
    }
    return countaaa;
}
void cube_list::print_all() {
    cube* currcube;
    BST* currword;
    for (int y = 0; y < 3; y++) {
        for (int z = 0; z < 3; z++) {
            for (int x = 0; x < 3; x++) {
                int count = 0;
                currcube = find_cube_3D(x, y, z);
                currword = currcube->BSTnext;
                cout << word_count(currword) << "\t";
                countaaa = 0;
            }
            cout << endl;
        }
        cout << endl;
    }
}
int cube_list::find_word_BST(BST* currcube, char* word) {
    BST* currword = currcube;
    while (currword != NULL) {
        if (strcmp(currword->data, word) == 0) { return 1; }
        if (strcmp(currword->data, word) < 0) { currword = currword->right; }
        else if (strcmp(currword->data, word) > 0) { currword = currword->left; }
    }
}
void cube_list::find_word(char* word) {
    cube* currcube;
    BST* currword;
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            for (int z = 0; z < 3; z++) {
                currcube = find_cube_3D(x, y, z);
                currword = currcube->BSTnext;
                if (find_word_BST(currword, word) == 1) {
                    cout << z << y << x << endl;
                }
            }
        }
    }
}
void cube_list::delete_word(int x, int y, int z, char* word) {
    cube* currcube = find_cube(x, y, z);
    cube* precube = currcube;
    BST* currword = currcube->BSTnext;
    BST* saveword = NULL;
    int right_left = 0;
    if (strcmp(currword->data, word) == 0) {
        if (currword->left == NULL && currword->right == NULL) {
            delete currword;
            currcube->BSTnext = NULL;
            return;
        }
        else if (currword->left != NULL && currword->right != NULL) {
            currword = currword->right;
            while (currword->left != NULL) {
                currword = currword->left;
            }
            strcpy(currcube->BSTnext->data, currword->data);
            delete currword;
            return;
        }
        else if (currword->left != NULL && currword->right == NULL) {
            currword = currword->left;
            if (currword->right == NULL) {
                strcpy(currcube->BSTnext->data, currword->data);
                delete currword;
                return;
            }
            else if (currword->right != NULL) {
                currword = currword->right;
                while (currword->left != NULL) {
                    currword = currword->left;
                }
                strcpy(currcube->BSTnext->data, currword->data);
                delete currword;
                return;
            }
        }
        else if (currword->left != NULL && currword->right != NULL) {
            saveword = currword;
            currword = currword->right;
            while (currword->left != NULL) {
                currword = currword->left;
            }
            strcpy(currcube->BSTnext->data, currword->data);
            delete currword;
            return;
        }
    }
    while (1) {
        if (strcmp(currword->data, word) > 0) {
            saveword = currword;
            right_left = 1;
            currword = currword->left;
        }
        else if (strcmp(currword->data, word) < 0) {
            saveword = currword;
            right_left = 0;
            currword = currword->right;
        }
        else if (strcmp(currword->data, word) == 0) {
            if (currword->left == NULL && currword->right == NULL) {
                delete currword;
                if (right_left == 1) {
                    saveword->left = NULL;
                }
                else if (right_left == 0) {
                    saveword->right = NULL;
                }
                return;
            }
            else if (currword->left == NULL && currword->right != NULL)
            {
                currword = currword->right;
                while (currword->left != NULL) {
                    currword = currword->left;
                }
                strcpy(saveword->data, currword->data);
                delete currword;
                return;
            }
            else if (currword->left != NULL && currword->right == NULL) {
                currword = currword->left;
                while (currword->right != NULL) {
                    currword = currword->left;
                }
                currword = currword->right;
                while (currword->left != NULL) {
                    currword = currword->right;
                }
                while (currword->left != NULL) {
                    currword = currword->left;
                }
                strcpy(saveword->data, currword->data);
                delete currword;
                return;
            }
            else if (currword->left != NULL && currword->right != NULL) {
                currword = currword->right;
                while (currword->left != NULL) {
                    currword = currword->right;
                }
                while (currword->left != NULL) {
                    currword = currword->left;
                }
                strcpy(saveword->data, currword->data);
                delete currword;
                return;
            }
        }
    }

}
void cube_list::preorder_print_word(BST* currword) {
    BST* currword1 = currword;
    if (currword1 != NULL) {
        cout << currword1->data << " ";
        preorder_print_word(currword1->left);
        preorder_print_word(currword1->right);
    }
}
void cube_list::inorder_print_word(BST* currword) {
    BST* currword1 = currword;
    if (currword1) {
        inorder_print_word(currword1->left);
        cout << currword1->data << " ";
        inorder_print_word(currword1->right);
    }
}
void cube_list::postorder_print_word(BST* currword) {
    BST* currword1 = currword;
    if (currword1) {
        postorder_print_word(currword1->left);
        postorder_print_word(currword1->right);
        cout << currword1->data << " ";
    }
}
void cube_list::print_word(int x, int y, int z) {
    cube* currcube = find_cube_3D(x, y, z);
    BST* currword = currcube->BSTnext;
    if (currword == NULL) {
        cout << "큐브에 단어가 없습니다" << endl;
        return;
    }
    cout << "Preorder : "; preorder_print_word(currword); cout << endl;
    cout << "Postorder : "; postorder_print_word(currword); cout << endl;
    cout << "Inorder : "; inorder_print_word(currword); cout << endl;
}
cube* cube_list::find_cube_3D(int x, int y, int z) {
    cube* currcube = head;
    int xpos = 0, ypos = 0, zpos = 0;
    while (1) {
        if (xpos == x) { break; }
        currcube = currcube->down;
        xpos++;
    }
    while (1) {
        if (ypos == y) { break; }
        currcube = currcube->right;
        ypos++;
    }
    while (1) {
        if (zpos == z) { break; }
        currcube = currcube->back;
        zpos++;
    }
    return currcube;
}
void cube_list::push_word(int x, int y, int z, char* word) {
    cube* currcube = find_cube_3D(x, y, z);
    BST* newword = new BST;
    strcpy(newword->data, word);
    if (currcube->BSTnext == NULL) {
        currcube->BSTnext = newword;
        return;
    }
    else if (currcube->BSTnext != NULL) {
        BST* currword = currcube->BSTnext;
        while (currword != NULL) {
            if (strcmp(currword->data, word) == 0) {
                return;
            }
            if (strcmp(currword->data, word) < 0)
            {
                if (currword->right == NULL) {
                    currword->right = newword;
                    return;
                }
                currword = currword->right;
            }
            else if (strcmp(currword->data, word) > 0) {
                if (currword->left == NULL) {
                    currword->left = newword;
                    return;
                }
                currword = currword->left;
            }
        }
    }
}
cube* cube_list::find_cube(int x, int y, int z) {
    cube* currcube = head;
    while (currcube != NULL) {
        if (currcube->x == x && currcube->y == y && currcube->z == z) {
            return currcube;
        }
        currcube = currcube->next;
    }
}
void cube_list::made_cube() {
    cube* load;
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            for (int z = 0; z < 3; z++) {
                cube* newblock = new cube;
                newblock->x = x;
                newblock->y = y;
                newblock->z = z;
                if (head == NULL) {
                    head = newblock;
                    save_cube = head;
                }
                else if (head != NULL) {
                    save_cube->next = newblock;
                    save_cube = save_cube->next;
                }
            }
        }
    }
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            for (int z = 0; z < 3; z++) {
                load = find_cube(x, y, z);
                if (x == 0) {
                    load->down = find_cube(x + 1, y, z);
                }
                else if (x == 1) {
                    load->up = find_cube(x - 1, y, z);
                    load->down = find_cube(x + 1, y, z);
                }
                else if (x == 2) {
                    load->up = find_cube(x - 1, y, z);
                }
                if (y == 0) {
                    load->right = find_cube(x, y + 1, z);
                }
                else if (y == 1) {
                    load->right = find_cube(x, y + 1, z);
                    load->left = find_cube(x, y - 1, z);
                }
                else if (y == 2) {
                    load->left = find_cube(x, y - 1, z);
                }
                if (z == 0) {
                    load->back = find_cube(x, y, z + 1);
                }
                else if (z == 1) {
                    load->back = find_cube(x, y, z + 1);
                    load->front = find_cube(x, y, z - 1);
                }
                else if (z == 2) {
                    load->front = find_cube(x, y, z - 1);
                }
            }
        }
    }
}

int main() {
    cube_list list;
    int x, y, z, command, x1, y1, z1, x2, y2, z2;
    char word[50];
    list.made_cube();
    ifstream stream;
    stream.open("WordBook.txt");
    while (!stream.eof())
    {
        stream >> z >> y >> x >> word;
        list.push_word(x, y, z, word);
    }
    while (1) {
        cout << "Enter Any Command(1 : Insert, 2 : Delete, 3 : Find, 4 : Print, 5 : Print_All, 6 : Turn, 7 : Exchange, 8 : Exit) : "; cin >> command;
        if (command == 1) {
            cin >> z >> y >> x >> word;
            list.push_word(x, y, z, word);
        }
        else if (command == 2) {
            cin >> z >> y >> x >> word;
            list.delete_word(x, y, z, word);
        }
        else if (command == 3) {
            cin >> word;
            list.find_word(word);
        }
        else if (command == 4) {
            cin >> z >> y >> x;
            list.print_word(x, y, z);
        }
        else if (command == 5) {
            list.print_all();
        }
        else if (command == 6) {
            cin >> x >> y >> z;
            list.turn(x, y, z);
        }
        else if (command == 7) {
            cin >> z1 >> y1 >> x1 >> z2 >> y2 >> x2;
            list.exchange(x1, y1, z1, x2, y2, z2);
        }
        else if (command == 8) {
            list.delete_cube();
            return 0;
        }
    }
    return 0;
}