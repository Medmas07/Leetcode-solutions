class Router {
private:
    vector<vector<int>> memory;
    int max_Size;
    map<int, vector<int>> destToTimes;
    unordered_set<string> packetSet;

    string generateKey(int s, int d, int t) {
        return to_string(s) + "_" + to_string(d) + "_" + to_string(t);
    }
    void removeOneTimestamp(int d, int t) {
    auto it = destToTimes.find(d);
    if (it == destToTimes.end()) return;
    auto &v = it->second;                   
    auto pos = lower_bound(v.begin(), v.end(), t);
    if (pos != v.end() && *pos == t) v.erase(pos);  
    if (v.empty()) destToTimes.erase(it);
}


public:
    Router(int memoryLimit) { max_Size = memoryLimit; }

    bool addPacket(int source, int destination, int timestamp) {
        string key = generateKey(source, destination, timestamp);

        if (packetSet.find(key) != packetSet.end())
            return false;
        packetSet.insert(key);

        vector<int> packet = {source, destination, timestamp};

        destToTimes[destination].push_back(timestamp);

        if (memory.size() < max_Size) {
            memory.push_back(packet);
            return true;
        } else {
            string evictedKey =
                generateKey(memory[0][0], memory[0][1], memory[0][2]);
            packetSet.erase(evictedKey);
            removeOneTimestamp(memory[0][1], memory[0][2]);
            memory.erase(memory.begin());

            memory.push_back(packet);
        }
        return true;
    }

    vector<int> forwardPacket() {
        vector<int> res;

        if (memory.empty())
            return res;

        res.push_back(memory[0][0]);
        res.push_back(memory[0][1]);
        res.push_back(memory[0][2]);
        string evictedKey =
            generateKey(memory[0][0], memory[0][1], memory[0][2]);
        packetSet.erase(evictedKey);
        removeOneTimestamp(memory[0][1], memory[0][2]);
        memory.erase(memory.begin());

        return res;
    }

    int getCount(int destination, int startTime, int endTime) {
        const auto it = destToTimes.find(destination);
        if (it == destToTimes.end())
            return 0;

        const vector<int>& timestamps = it->second;

        auto low = lower_bound(timestamps.begin(), timestamps.end(), startTime);
        auto high = upper_bound(timestamps.begin(), timestamps.end(), endTime);

        return high - low;
    }
};