//https://www.hackerrank.com/contests/w15/challenges/haunted-house/copy-from/1387251929
/*
It is a well-known fact that Mr. Krabs owns a very popular restaurant, known as the Krusty Krab. He makes a lot of money from his restaurant, and all day long he's only counting his money. Not satisfied with his billions, he also opened an amusement park, called Krustyland, which contains lots of famous attractions, like roller coasters and ferris wheels. Recently, he has decided to open a haunted house. It is the scariest haunted house ever! In fact, it is so scary, that most people don't even want to go inside alone.

There are  people who want to visit the haunted house. The  person will only go if at least  other people will go with him. Additionally, that person doesn't want to go with more than  other people, since it would ruin the experience for them.

What is the maximum number of people that can visit the haunted house at one time so that no constraint is violated?

Input Format

The first line contains a single integer, , the number of people.

 lines follow. The  line contains two integers,  and , which are the minimum and maximum number of people the  person wants to go with, respectively.

Constraints


Output Format

Output a single integer, the maximum number of people Mr. Krabs can lure into the haunted house.

Sample Input

6
1 2
1 4
0 3
0 1
3 4
0 2
Sample Output

3
*/




#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {  
    int n, l, r;
    cin >> n;
    vector<int> res(300005, 0);
    for(int i = 0; i < n; i++){
        cin >> l >> r;
        
        res[l] += 1;
        
        res[r+1] -= 1;
    }
    
    for(int i = 0; i < 300004; i++){
        res[i+1] = res[i]+res[i+1];
    }
    
    // for(auto ele : res){
    //     cout << ele << " ";
    // }cout << endl;
    
    int ans = 0;
    for(int i = 0; i < 300005; i++){
        if(i+1 <= res[i]){
            ans = max(ans, i + 1);
        }
    }
    cout << ans << endl;
    return 0;
}
