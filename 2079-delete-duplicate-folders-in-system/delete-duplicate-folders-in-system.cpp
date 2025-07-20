class Solution {
    struct Node{
        unordered_map<string,Node*> children;
        string name;
        bool is_deleted=false;
    };

    unordered_map<string, vector<Node*>> serial_map;

    //Step 1: Build Tree
    Node* buildTree(vector<vector<string>>&paths){
        Node* root=new Node();

        for(auto &path:paths){
            Node* cur=root;

            for(auto &folder:path){
                if(!cur->children.count(folder)){
                    cur->children[folder]=new Node();
                    cur->children[folder]->name=folder;
                }
                cur=cur->children[folder];
            }
        }
        return root;
    }

    //Step 2: Serailize tree in postorder
    string serialize(Node* node){
        if(node->children.empty()){
            return "";
        }

        vector<pair<string,string>> serialized;

        for(auto &[name,child]:node->children){
            serialized.push_back({name,serialize(child)});
        }

        sort(serialized.begin(),serialized.end());

        string res;

        for(auto &[name,s]:serialized){
            res+=name+"("+s+")";
        }

        serial_map[res].push_back(node);

        return res;
    }

    //Step 3: Mark Duplicates
    void markduplicates(){
        for(auto& [serial,nodes]:serial_map){
            if(nodes.size()>1){
                for(Node* node:nodes){
                    node->is_deleted=true;
                }
            }
        }
    }

    //Step 4: DFS to collect valid paths
    void collectpaths(Node* node, vector<string>&cur,vector<vector<string>>&res){
        for(auto &[name,child]:node->children){
            if(child->is_deleted){
                continue;
            }

            cur.push_back(name);
            res.push_back(cur);

            collectpaths(child,cur,res);

            cur.pop_back();
        }
    }
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root=buildTree(paths);

        serialize(root);

        markduplicates();

        vector<vector<string>> res;

        vector<string> cur;

        collectpaths(root,cur,res);

        return res;
    }
};