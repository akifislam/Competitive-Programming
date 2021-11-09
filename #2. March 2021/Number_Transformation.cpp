//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-03-09 14:48:59

#include <bits/stdc++.h>
using namespace std;

char gap = 32;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << '{';
    for (const auto &x : v)
        os << gap << x;
    return os << '}';
}

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p)
{
    return os << '(' << p.first << gap << p.second << ')';
}

vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,
                   37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79,
                   83, 89, 97, 101, 103, 107, 109, 113, 127, 131,
                   137, 139, 149, 151, 157, 163, 167, 173, 179, 181,
                   191, 193, 197, 199, 211, 223, 227, 229, 233, 239,
                   241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307,
                   311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373,
                   379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439,
                   443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503,
                   509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593,
                   599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659,
                   661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743,
                   751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827,
                   829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919,
                   929, 937, 941, 947, 953, 967, 971,
                   977, 983, 991, 997, 1009};

vector<int> prime_factors[1001];


void queuePrint(queue<int> qq) {
    cout<<"=-----="<<endl;
    while(!qq.empty()){
        cout<<qq.front()<<" ";
        qq.pop();
    }
    cout<<endl;
    cout<<"=-----="<<endl;

}
void prime_factor_generator()
{

    for (int i = 1; i < 1001; i++)
    {

        for (int j = 0; primes[j] < i; j++)
        {
            if (i % primes[j] == 0)
            {
                prime_factors[i].push_back(primes[j]);
            }
        }
        // if(!isPrime) vec[i];
    }
}


int main()
{
    prime_factor_generator();

    int testcase;
    cin >> testcase;

    while (testcase--) {
        int s, t;
        cin >> s >> t;

        queue<int> q;
        int distance[1001];
        fill(distance,distance+1001,5000);

        int current_distance = 0;
        q.push(s);
        distance[s] = current_distance;

        while(q.size()<5) {

            int temp_s = q.front(); //6
            q.pop();

            for (int i = 0; i < prime_factors[temp_s].size(); i++) {
                if(temp_s%prime_factors[temp_s][i] == 0) {
                    q.push(temp_s + prime_factors[temp_s][i]);
//                    distance[q.front()] = distance[temp_s] +1;
                    distance[q.front()] = min(distance[q.front()], distance[temp_s]+1);
                }

                //Queue Print
                queuePrint(q);
                //Array Print
                cout<<"-------"<<endl;
                cout<<endl;
                for (int i = 0; i <10 ; i++) {
                    cout<<distance[i]<<" ";
                }
                cout<<endl;
                cout<<"-------"<<endl;


            }

        }

    }
}
