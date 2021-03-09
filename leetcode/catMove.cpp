//
// Created by Edison King on 2020/3/14.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void solver(vector<vector<vector<int>>>& videos, int& result, int start, vector<int> feature, const vector<int>& visited) {
    if (start == videos.size()) {
        return;
    }
    auto& frame = videos[start];
    auto iter = std::find(frame.begin(), frame.end(), feature);
    if (iter != frame.end()) {
        *iter = visited;
        result += 1;
        solver(videos, result, start + 1, feature, visited);
    }
}

int longestCatMove(vector<vector<vector<int>>>& videos) {
    int result = 0;
    if (videos.size() == 0) {
        return result;
    }
    vector<int> visited{-1, -1};
    for (int i = 0; i < videos.size(); ++i) {
        auto& frame = videos[i];
        for (const auto& feature: frame) {
            if (feature != visited) {
                int local = 0;
                solver(videos, local, i, feature, visited);
                result = std::max(result, local);
            }
        }
    }
    return result;
}

int main() {
    vector<vector<vector<int>>> videos;
    videos.push_back({{1, 1}, {2, 2}});
    videos.push_back({{1, 1}, {1, 4}});
    videos.push_back({{1, 1}, {2, 2}});
    videos.push_back({{2, 2}, {1, 4}});
    videos.push_back({});
    videos.push_back({});
    videos.push_back({{1, 1}});
    videos.push_back({{1, 1}});

    cout << longestCatMove(videos) << endl;

    return 0;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int M;
        cin >> M;
        vector<vector<vector<int>>> videos;
        for (int j = 0; j < M; ++j) {
            vector<vector<int>> frames;
            int a;
            cin >> a;
            for (int k = 0; k < a; ++k) {
                int s, e;
                cin >> s;
                cin >> e;
                frames.push_back(vector<int>{s, e});
            }
            videos.push_back(frames);
        }
        cout << longestCatMove(videos) << endl;
    }

    return 0;
}
