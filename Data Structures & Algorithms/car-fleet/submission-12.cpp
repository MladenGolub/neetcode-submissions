class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        stack<double> st;

        map<int, int> mapa;
        for(int i = 0; i < position.size(); i++) {
            mapa[position[i]] = speed[i];
        }//sada imam sortiranu mapu sa pozicijama i brzinama, sortiranu od najmanje ka najvecoj preko pozicija, jer njih koristim kao kljuceve

        for(auto it = mapa.rbegin(); it != mapa.rend(); ++it) {
            if(!st.empty() && ((double)(target - it->first) / it->second <= st.top())) {
                cout << it->first << it->second;
            } else {
                st.push((double)(target - it->first) / it->second);
            }
        }
        int size = st.size();
        cout << size << endl;
        int i = 0;
        while(i < st.size()) {
            cout << st.top() << endl;
            st.pop();
            i++;
        }
        return size;
    }
};
