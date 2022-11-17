#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream myfile;
    myfile.open("13.txt");
    vector<pair<long long, long long> > is;
    vector<pair<long long, long long> > is2;
    auto tmp1 = 0, remainder = 0;
    string st;
    myfile >> tmp1;
    while (getline(myfile, st, ',')) {
        int found = 0;
        if (stringstream(st) >> found) {
            auto a = tmp1 % found;
            is.push_back(make_pair(found, found - a));
            is2.push_back(make_pair(remainder, found));
        }
        remainder++;
    }
    auto cur = min_element(is.begin(), is.end(), [](auto a, auto b) { return a.second < b.second; });
    cout << "Part1: " << cur->first * cur->second << endl;


    long long i = is2[0].second, t = 1;
    long long nxt_i = is2[0].second;
    for (int j = 0; j < is2.size()-1; ++j) {
        long long t = 1;
        while(true) {
            long long t1 = (i + (nxt_i * t));
            auto next_b = t1 + is2[j+1].first;
            if((next_b % is2[j+1].second) ==0) {
                i = t1;
                break;
            }
            t++;
        }
        nxt_i *= is2[j+1].second;
    }
    cout << "Part2: " << i << endl;
    return 0;
}
