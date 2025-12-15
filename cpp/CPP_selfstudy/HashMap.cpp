/* 값을 넣으면, 그 값을 바로 찾을 수 있게 해주는 자료구조
unordered_map<KeyType, ValueType> : 해쉬 테이블
key : 숫자 값
value : 그 숫자의 인덱스
*/

#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

class HASH_MAP{
    public:
    int hashmap(){
        unordered_map<int,int> mp;

        int key = 1;
        int value = 0;
        // 삽입, 갱신
        mp[key] = value; // 없으면 생성, 있으면 갱신
        // {key : value}
        mp.emplace(key,value); 

        // 존재여부 확인(가장 중요)
        if(mp.find(key) != mp.end()){int val = mp.find(key)->second}
        // find(key) key값이 존재하면 iterator를 반환하고 존재하지 않으면
        // mp.end()와 같은 값을 반환한다.
        // mp.end()는 끝을 나타내는 iterator를 반환함.

        // count
        mp.count(key); //0 or 1
        if(mp.count(key)){
            // key 존재여부 확인
        }
        // erase
        mp.erase(key); //해당 key삭제

        // clear
        mp.clear(); // 전부 삭제

        // size
        mp.size(); // 현재 key갯수

        // 가장 흔한 사용 패턴
        // 빈도수 세기
        unordered_map<int,int> cnt;
        for (int x: a) cnt[x]++; // a는 iterator로 내부의 값을 하나씩 가져온다.

        unordered_map<string,int> fruits;
        fruits["apple"] = 3;
        fruits["banana"] = 5;

        for (const auto& p:fruits){ // const & : 복사 없이 순회한다.(권장)
            cout << p.first << " " << p.second << endl;
        }
        // first : key값
        // second : value값을 의미한다.
        // unordered map이기 때문에, 출력 순서는 보장되지 않는다.
    }
};
