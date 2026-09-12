class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {

        int n = s.size();
        vector<bool> canSegment(n + 1, false);
        canSegment[n] = true;  // prazan sufiks se uvek moze "segmentirati"
        
        for (int i = n - 1; i >= 0; i--) {
            for (string& word : wordDict) {
                int len = word.size();
                if (i + len <= n && s.compare(i, len, word) == 0 && canSegment[i + len]) {
                    canSegment[i] = true;
                    break;
                }
            }
        }
        
        if (!canSegment[0]) return {};
            
        vector<string> res;
        backtrack(0, s, wordDict, res);
        return res;
        
    }

    void backtrack(int indexSent, string& trSent, vector<string>& wordDict, vector<string>& res) {
        //indexSent ce mi reci na koju poziciju unatar trSent treba da dodamo ' '
        //trSent je trenutno modifikovani string
        //wordDict je pocetni niz iz koje izvlacimo reci
        //res je samo niz u kojem cuvamo sve moguce recenice

        if(indexSent >= trSent.size()) {
            trSent.pop_back();
            res.push_back(trSent);
            return;    
        }
        

        for(int j = 0; j < wordDict.size(); j++) {
            if(isAtStart(trSent, wordDict[j], indexSent)) {
                cout << wordDict[j] << endl;
                string novi = trSent;
                novi.insert(indexSent + wordDict[j].size(), " ");
                backtrack(indexSent + 1 + wordDict[j].size(), novi, wordDict, res);
            }
        }   

    }

    bool isAtStart(string& sent, string& word, int indexSent) {
        if(indexSent + word.size() > sent.size()) return false;

        for(int i = 0; i < word.size(); i++) {
            if(sent[indexSent + i] != word[i]) return false;
        }

        return true;

    }
};