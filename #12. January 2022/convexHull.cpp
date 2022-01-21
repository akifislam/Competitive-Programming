#include <bits/stdc++.h>
using namespace std;

int no_of_points;
vector<pair<int, int>> points;
vector<pair<int, int>> results;

int orientation(int p, int q, int r)
{
    // int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    int value =
        (((points[q].second - points[p].second) * (points[r].first - points[q].first)) -
         ((points[q].first - points[p].first) * (points[r].second) - (points[q].second)));

    if (value == 0)
        return 0; // colinear
    else if (value > 0)
        return 1;
    else
        return 2;
}

int findLeftMostPoint()
{
    int leftMostindex = 0;

    for (int i = 1; i < points.size(); i++)
    {
        if (points[leftMostindex].first > points[i].first)
        {
            leftMostindex = i;
        }
    }
    cout << "Left Most Index : " << leftMostindex << endl;
    cout << "Starting point is : (" << points[leftMostindex].first << "," << points[leftMostindex].second << ") " << endl;
    return leftMostindex;
}

void JarvisMarch(int leftMostIndex)
{
    // Case : 01 - If there is sufficient points
    if (points.size() < 3)
    {
        cout << "There are not sufficient points to make convex hull" << endl;
        return;
    }

    int p = leftMostIndex;

    do
    {
        results.push_back({points[p].first, points[p].second});
        int q = (p + 1) % no_of_points;

        for (int i = 0; i < no_of_points; i++)
        {
            if (orientation(p, i, q) == 2)
                q = i;
        }
        p = q;
    } while (p != leftMostIndex);
}
int main()
{

    points.push_back({0, 3});
    points.push_back({2, 2});
    points.push_back({1, 1});
    points.push_back({2, 1});
    points.push_back({3, 0});
    points.push_back({0, 0});
    points.push_back({3, 3});

    no_of_points = points.size();

    int leftMostIndex = findLeftMostPoint();
    JarvisMarch(leftMostIndex);

    for (int i = 0; i < results.size(); i++)
    {
        cout << "(" << results[i].first << "," << results[i].second << ") " << endl;
    }
}
