/*
std::vector : 크기가 자동으로 늘어나는 배열
내부적으로는 연속된 메모리(배열처럼) 저장됨.

*/

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class VECTOR{
public:
    void METHOD(){
        vector<int> a; // 빈 벡터
        vector<int> b(5); // 크기 5, 0으로 초기화 [0,0,0,0,0]
        vector<int> c(5,7); // 크기 5, 7로 초기화 [7,7,7,7,7]
        vector<int> d = {1,2,3}; // 리스트 초기화
        vector<int> e(d); // 복사

        // 현재 원소 갯수
        a.size();

        // 비었는지 확인
        if( a.empty() ){}

        // 맨 뒤에 추가
        a.push_back(10);

        // 맨 뒤 원소 제거, 비어있으면 에러 발생
        a.pop_back();

        // 마지막, 첫 원소 참조, 비어있으면 에러 발생
        a.front();
        a.back();

        // operator [] , at()
        // 벡터 해당 인덱스 접근하는 방법

        // 전부 삭제 (size = 0)
        a.clear();

        // size를 n으로 맞춤 (늘어나면 기본값 / val로 채움)
        a.resize(10); //사이즈를 10으로 맞춘다. 기본값 : 0
        a.resize(10, -1); // 사이즈 10, 기본값 : -1
        
        
        // 중간 삽입/삭제 (느릴 수 있음)
        int idx = 5;
        a.insert(a.begin()+idx, 99); // 시작위치부터 idx만큼 떨어진 곳에 삽입
        a.erase(a.begin() + idx);

        // 순회 방법
        // index for
        for(int i = 0;i<(int)a.size();i++) cout <<a[i];

        // range - for
        for (int x: a) cout<<x;

        // range - for (수정)
        // &x 는 벡터 원소 그 자체를 가리키는 참조이다. 즉, 벡터에 붙은 별명(alias)라고 보면 된다.
        for (int &x : a) x += 1; // 참조(&)붙여야 벡터안의 값이 실제로 바뀐다.
        for (const int &x : a) cout << x ; // 읽기만 할 때는 복사 비용 줄이기위해 const까지 붙인다.
        // iterator (begin/end)
        // end는 마지막 원소가 아니라 마지막 다음을 가리킨다.
        for (auto it = a.begin(); it!= a.end(); it++){
            cout << *it;
        } // it는 원소 자체가 아니라, 해당 원소의 위치를 가리키는 iterator, 포인터와 같은 역할을 한다.
        

        // 자주 사용되는 패턴
        // 1. 값 찾기
        int target  = 1;
        auto it = find(a.begin(), a.end(), target);
        if(it != a.end()){
            int idx = it - a.begin(); //몇 번째 인덱스인지 찾는다. 
        }

        // 2. 정렬
        sort(a.begin(), a.end()); // 오름차순 정렬
        sort(a.begin(),a.end(),greater<int>()); // 내림차순
        

        // 3. 이차원 벡터
        vector<vector<int>> a; // 바깥 벡터는 행, 안쪽 벡터는 열이라고 보면 된다.

        // n행 m열, 초기값 0으로 만들기 (가장 많이 씀)
        int n = 3, m=4;
        vector<vector<int>> grid(n,vector<int>(m,0));
        // grid는 3x4이고, 전부 0

        grid[1][2] = 5; // 2번째 행, 3번째 열

        // n행만 만들고, 각 행의 길이는 나중에 (가변 길이 / ragged)
        vector<vector<int>> g(n); // n행, 각 행은 비어있음.
        g[0].push_back(1);
        g[0].push_back(2);
        g[1].push_back(10);
        // 이렇게 하면 행마다 길이가 달라도 됨.

        // 입력으로 nxm채우기
        vector<vector<int>> a(n,vector<int>(m));
        for (int i = 0; i<n;i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }

        // 리스트로 바로 만드는 방법
        vector<vector<int>> a = {
            {1,2,3},
            {4,5,6}
        };


    }
};