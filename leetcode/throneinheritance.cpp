#include <vector>
#include <string>
#include <unordered_map>

class ThroneInheritance {
public:
    std::unordered_map<std::string, bool> alive;
    std::unordered_map<std::string, std::vector<std::string>> graph;
    std::string king;
    ThroneInheritance(std::string kingName) {
        king = kingName;
        alive[kingName] = 1;
    }
    
    void birth(std::string parentName, std::string childName) {
        graph[parentName].push_back(childName);
        alive[childName] = true;
    }
    
    void death(std::string name) {
        alive[name] = false;
    }
    
    std::vector<std::string> getInheritanceOrder() {
        std::vector<std::string> l;
        
        std::vector<std::string> stack;
        std::string dude;
        stack.push_back(king);
        while(!stack.empty()) {
            dude = stack.back();
            std::vector<std::string>& cur = graph[dude];
            stack.pop_back();
            if (alive[dude]) {
                l.push_back(dude);
            }
            for (int i = cur.size() - 1; i >= 0; i--) {
                stack.push_back(cur[i]);
            }
        }
        return l;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */