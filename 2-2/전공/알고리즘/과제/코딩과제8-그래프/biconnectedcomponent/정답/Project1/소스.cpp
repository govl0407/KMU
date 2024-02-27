
#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

#define MAX_NODE 100

struct node {
    int num;
    node* link;

    //생성자
    node(int n, node* _link) {
        num = n;
        link = _link;
        // cout<<this<<": node생성"<<endl;
    }

    //소멸자
    ~node() {
        // cout<<this<<": node소멸"<<endl;
    };
};

class AdjListGraph {
public:
    int size;
    node* list[MAX_NODE] = { nullptr, };    // 인접 리스트

    //생성자
    AdjListGraph(int n) {
        // cout<<this<<": list생성"<<endl;
        size = n;
    }

    //소멸자
    ~AdjListGraph() {
        // for(int i=0; i<size; i++){
        //     if(list[i] != nullptr){
        //         node* haed = list[i];
        //         delete list[i];

        //         while(haed->link != nullptr){
        //             node* tmp = haed->link;
        //             delete haed->link;
        //             haed = tmp;
        //         }

        //     }
        // }

        // cout<<this<<": list소멸"<<endl;
    }

    //엣지 연결
    void insertEdge(int u, int v) {
        list[u - 1] = new node(v, list[u - 1]);   // 새로운 node의 포인터는 기존 head pointer link
    }

    void show() {
        cout << "show" << endl;
        for (int i = 0; i < size; i++) {
            cout << i + 1 << " : ";
            node* head = list[i];
            while (head != nullptr) {
                cout << head->num << ' ';
                head = head->link;
            }
            cout << endl;
        }

    }
};

int dfsNumber[MAX_NODE];
int back[MAX_NODE];
int dfn;
int biconnect_component;
vector<int> articulation_point_list;

void Bicomp_DFS(AdjListGraph graph, int v) {
    // cout<<"visit : " <<v<<endl;

    dfn++;

    //초기화
    dfsNumber[v - 1] = dfn;
    back[v - 1] = dfn;

    node* node_ = graph.list[v - 1]; //v와 연결된 노드

    while (node_ != nullptr) {
        int w = node_->num;

        if (!dfsNumber[w - 1]) {//v와 연결된 노드 w가 아직 방문하지 않은 노드라면
            Bicomp_DFS(graph, w); //dfs수행

            //recursive가 끝나고 돌아오면 관절 포인트가 아닌지 확인
            if (back[w - 1] < dfsNumber[v - 1]) {//w의 back이 v보다 작으면 == 더 위로 올라갈 수 있으면 : v의 back update
                //back[v] = min(back[v],back[w])
                if (back[v - 1] > back[w - 1]) {
                    back[v - 1] = back[w - 1];
                }
            }
            else { //w의 back이 v보다 같거나 크면 == w를 root로 하는 subtree == new bicomp
                //v는 관절 포인트
                biconnect_component++;
                articulation_point_list.push_back(v);
            }
        }
        else {//v와 연결된 노드 w가 이미 방문한 노드라면 == back edge
            //back[v] update
            if (back[v - 1] > dfsNumber[w - 1]) {
                back[v - 1] = dfsNumber[w - 1];
            }
        }

        node_ = node_->link;
    }
    return;
}

int main() {

    /*제출용 - 입력받기*/
    int t;
    cin >> t;

    while (t--) {
        int n; // 노드의 개수 (3~1,000)
        cin >> n;

        //초기화
        dfn = 0;
        biconnect_component = 0;
        articulation_point_list.clear();
        for (int i = 0; i < n; i++) {
            dfsNumber[i] = 0;
            back[i] = 0;
        }

        //각 노드는 1부터 n까지 차례로 번호가 부여됨
        AdjListGraph graph(n);

        int u, v; //시작 정점, 끝정점
        int tmp;
        for (int i = 0; i < n; i++) {
            cin >> u >> tmp;
            while (tmp--) {
                cin >> v;
                graph.insertEdge(u, v);
            }
        }

        // graph.show();

        Bicomp_DFS(graph, 1);

        sort(articulation_point_list.begin(), articulation_point_list.end());
        cout << biconnect_component << endl;

        //맨처음 시작 노드는 무조건 biconnect_component로 인식되므로 list에서 빼줌
        articulation_point_list.erase(articulation_point_list.begin());
        biconnect_component--;

        if (biconnect_component) { //1개이상일때만
            //중복되는것도 빼줌
            int i = 1;
            tmp = articulation_point_list[0];

            while (true) {

                if (i == articulation_point_list.size()) {
                    break;
                }

                if (tmp == articulation_point_list[i]) {
                    articulation_point_list.erase(articulation_point_list.begin() + i);
                    biconnect_component--;
                }
                else {
                    tmp = articulation_point_list[i];
                    i++;
                }
            }

            //출력
            cout << biconnect_component << " ";
            for (int i = 0; i < biconnect_component; i++) {
                cout << articulation_point_list[i] << " ";
            }
            cout << endl;
        }
        else {
            cout << 0 << endl;
        }



    }




    /*디버깅*/

    // int n = 11;     //4 3 5 8 9
    // AdjListGraph graph(n);
    // graph.insertEdge(1,3);
    // graph.insertEdge(2,3);
    // graph.insertEdge(3,1);
    // graph.insertEdge(3,2);
    // graph.insertEdge(3,4);
    // graph.insertEdge(3,5);
    // graph.insertEdge(4,3);
    // graph.insertEdge(5,3);
    // graph.insertEdge(5,6);
    // graph.insertEdge(5,7);
    // graph.insertEdge(6,5);
    // graph.insertEdge(6,8);
    // graph.insertEdge(7,5);
    // graph.insertEdge(7,8);
    // graph.insertEdge(8,6);
    // graph.insertEdge(8,7);
    // graph.insertEdge(8,9);
    // graph.insertEdge(9,8);
    // graph.insertEdge(9,10);
    // graph.insertEdge(9,11);
    // graph.insertEdge(10,9);
    // graph.insertEdge(10,11);
    // graph.insertEdge(11,9);
    // graph.insertEdge(11,10);


    // int n = 5; //3 2 3 4
    // AdjListGraph graph(n);
    // graph.insertEdge(1,2);
    // graph.insertEdge(2,1);
    // graph.insertEdge(2,3);
    // graph.insertEdge(3,2);
    // graph.insertEdge(3,4);
    // graph.insertEdge(4,3);
    // graph.insertEdge(4,5);
    // graph.insertEdge(5,4);

    // graph.show();

    // Bicomp_DFS(graph,1);

    // sort(articulation_point_list.begin(),articulation_point_list.end());

    // //맨처음 시작 노드는 무조건 biconnect_component로 인식되므로 list에서 빼줌
    // articulation_point_list.erase(articulation_point_list.begin());
    // biconnect_component--;

    // //중복되는것도 빼줌
    // int i =1;
    // int tmp = articulation_point_list[0];

    // while(true){

    //     if(i == articulation_point_list.size()){
    //         break;
    //     }

    //     if(tmp == biconnect_component_list[i]){
    //         biconnect_component_list.erase(articulation_point_list.begin()+i);
    //         biconnect_component--;
    //     }
    //     else{
    //         tmp = articulation_point_list[i];
    //         i++;
    //     }
    // }

    // //출력
    // cout<<biconnect_component<<" ";
    // for(int i=0;i<biconnect_component;i++){
    //     cout<<biconnect_component_list[i]<<" ";
    // }
    // cout<<endl;


}