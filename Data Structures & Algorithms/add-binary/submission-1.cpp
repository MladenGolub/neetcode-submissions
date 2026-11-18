class Solution {
public:
    string addBinary(string a, string b) {
        
        int i = a.size() - 1;
        int j = b.size() - 1;
        int c = 0;

        string res = "";

        while(i >= 0 || j >= 0) {
            if(i >= 0 && j >= 0) {
                if(a[i] == '1' && b[j] == '1') {
                    if(c) {
                        res = "1" + res;
                        c = 1;
                    } else {
                        res = "0" + res;
                        c = 1;
                    }
                    i--;
                    j--;
                } else if(a[i] == '1' || b[j] == '1') {
                    if(c) {
                        res = "0" + res;
                        c = 1;
                    } else {
                        res = "1" + res;
                        c = 0;
                    }
                    i--;
                    j--;
                } else {
                    if(c) {
                        res = "1" + res;
                        c = 0;
                    } else {
                        res = "0" + res;
                        c = 0;
                    }
                    i--;
                    j--;
                }
            } else if(i >= 0) {
                if(a[i] == '1') {
                    if(c) {
                        res = "0" + res;
                        c = 1;
                    } else {
                        res = "1" + res;
                        c = 0;
                    }
                    i--;
                } else {
                    if(c) {
                        res = "1" + res;
                        c = 0;
                    } else {
                        res = "0" + res;
                        c = 0;
                    }
                    i--;
                }
            } else {
                if(b[j] == '1') {
                    if(c) {
                        res = "0" + res;
                        c = 1;
                    } else {
                        res = "1" + res;
                        c = 0;
                    }
                    j--;
                } else {
                    if(c) {
                        res = "1" + res;
                        c = 0;
                    } else {
                        res = "0" + res;
                        c = 0;
                    }
                    j--;
                }
            }
        }
        if(c) res = "1" + res;
        return res;

    }
};