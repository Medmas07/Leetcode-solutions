class Spreadsheet {
private:
    unordered_map<string, int> matrix;
    bool isNumber(const std::string& str) {
        if (str.empty())
            return false;

        for (char ch : str) {
            if (!isdigit(ch))
                return false;
        }
        return true;
    }

public:
    Spreadsheet(int rows) {
        /*for (int i = 0; i < 26; i++) {
            for (int j = 0; j < rows; j++) {
                string tmp = "";
                tmp += ('A' + i);
                tmp += to_string(j);
                matrix[tmp] = 0;
            }
        }*/
    }

    void setCell(string cell, int value) { matrix[cell] = value; }

    void resetCell(string cell) { matrix[cell] = 0; }

    int getValue(string formula) {
        int pos = formula.find('+');

        string first = formula.substr(1, pos - 1);
        string second = formula.substr(pos + 1);
        int val1 = isNumber(first) ? stoi(first) : matrix[first];
        // cout<<"val1  "<<val1<<endl;

        int val2 = isNumber(second) ? stoi(second) : matrix[second];
        // cout<<"val2  "<<val2<<endl;
        return val1 + val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */