class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        int fleets = 0;
        stack<double> stk;

        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), greater<pair<int, int>>());

        for (int i = 0; i < cars.size(); i++) {
            double time = (double)(target - cars[i].first) / cars[i].second;
            
            if (stk.empty()) {
                stk.push(time);
                fleets++;
                continue;
            }

            if (stk.top() < time) {
                stk.push(time);
                fleets++;
            }
        }

        return fleets;
    }
};
