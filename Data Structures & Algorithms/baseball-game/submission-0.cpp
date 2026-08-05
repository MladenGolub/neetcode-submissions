class Solution {

    stack<int> stek;

public:
    int calPoints(vector<string>& operations) {
        
        for(string op : operations) {
            if(op == "+") {
                int prvi = stek.top();
                stek.pop();
                int drugi = stek.top();
                stek.pop();
                stek.push(drugi);
                stek.push(prvi);
                stek.push(prvi + drugi);
            }
            else if(op == "C") {
                stek.pop();
            }
            else if(op == "D") {
                int pom = stek.top();
                stek.push(pom * 2);
            } else {
                stek.push(stoi(op));
            }
        }
        int sum = 0;
        while(!stek.empty()) {
            sum += stek.top();
            cout << stek.top() << " ";
            stek.pop();
        }
        return sum;

    }
};