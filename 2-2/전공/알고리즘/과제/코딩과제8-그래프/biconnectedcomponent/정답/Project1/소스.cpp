
#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

#define MAX_NODE 100

struct node {
    int num;
    node* link;

    //������
    node(int n, node* _link) {
        num = n;
        link = _link;
        // cout<<this<<": node����"<<endl;
    }

    //�Ҹ���
    ~node() {
        // cout<<this<<": node�Ҹ�"<<endl;
    };
};

class AdjListGraph {
public:
    int size;
    node* list[MAX_NODE] = { nullptr, };    // ���� ����Ʈ

    //������
    AdjListGraph(int n) {
        // cout<<this<<": list����"<<endl;
        size = n;
    }

    //�Ҹ���
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

        // cout<<this<<": list�Ҹ�"<<endl;
    }

    //���� ����
    void insertEdge(int u, int v) {
        list[u - 1] = new node(v, list[u - 1]);   // ���ο� node�� �����ʹ� ���� head pointer link
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

    //�ʱ�ȭ
    dfsNumber[v - 1] = dfn;
    back[v - 1] = dfn;

    node* node_ = graph.list[v - 1]; //v�� ����� ���

    while (node_ != nullptr) {
        int w = node_->num;

        if (!dfsNumber[w - 1]) {//v�� ����� ��� w�� ���� �湮���� ���� �����
            Bicomp_DFS(graph, w); //dfs����

            //recursive�� ������ ���ƿ��� ���� ����Ʈ�� �ƴ��� Ȯ��
            if (back[w - 1] < dfsNumber[v - 1]) {//w�� back�� v���� ������ == �� ���� �ö� �� ������ : v�� back update
                //back[v] = min(back[v],back[w])
                if (back[v - 1] > back[w - 1]) {
                    back[v - 1] = back[w - 1];
                }
            }
            else { //w�� back�� v���� ���ų� ũ�� == w�� root�� �ϴ� subtree == new bicomp
                //v�� ���� ����Ʈ
                biconnect_component++;
                articulation_point_list.push_back(v);
            }
        }
        else {//v�� ����� ��� w�� �̹� �湮�� ����� == back edge
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

    /*����� - �Է¹ޱ�*/
    int t;
    cin >> t;

    while (t--) {
        int n; // ����� ���� (3~1,000)
        cin >> n;

        //�ʱ�ȭ
        dfn = 0;
        biconnect_component = 0;
        articulation_point_list.clear();
        for (int i = 0; i < n; i++) {
            dfsNumber[i] = 0;
            back[i] = 0;
        }

        //�� ���� 1���� n���� ���ʷ� ��ȣ�� �ο���
        AdjListGraph graph(n);

        int u, v; //���� ����, ������
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

        //��ó�� ���� ���� ������ biconnect_component�� �νĵǹǷ� list���� ����
        articulation_point_list.erase(articulation_point_list.begin());
        biconnect_component--;

        if (biconnect_component) { //1���̻��϶���
            //�ߺ��Ǵ°͵� ����
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

            //���
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




    /*�����*/

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

    // //��ó�� ���� ���� ������ biconnect_component�� �νĵǹǷ� list���� ����
    // articulation_point_list.erase(articulation_point_list.begin());
    // biconnect_component--;

    // //�ߺ��Ǵ°͵� ����
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

    // //���
    // cout<<biconnect_component<<" ";
    // for(int i=0;i<biconnect_component;i++){
    //     cout<<biconnect_component_list[i]<<" ";
    // }
    // cout<<endl;


}