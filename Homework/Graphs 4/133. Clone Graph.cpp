class Solution {
private: 
    void createNeighbors(Node *newGraph, Node *oldGraph, vector<Node*> &nodeExist) {
        for (auto &i: oldGraph->neighbors) {
            Node *temp = NULL;
            if (nodeExist[i->val] == NULL) {
                nodeExist[i->val] = new Node(i->val);
            }
            temp = nodeExist[i->val];
            newGraph->neighbors.push_back(temp);
        }
    }

    void cloneHelper(Node *newGraph, Node *oldGraph, vector<Node*> &nodeExist, vector<bool> &visited) {
        createNeighbors(newGraph, oldGraph, nodeExist);
        visited[newGraph->val] = true;
        for (int i=0; i<oldGraph->neighbors.size(); i++) {
            if (visited[newGraph->neighbors[i]->val]) continue;
            cloneHelper(newGraph->neighbors[i], oldGraph->neighbors[i], nodeExist, visited);
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;

        vector<Node*> nodeExist(101, NULL);
        Node *newGraph = new Node(node->val);
        nodeExist[newGraph->val] = newGraph;
        vector<bool> visited (101, false);
        cloneHelper(newGraph, node, nodeExist, visited);
        
        return newGraph;
    }
};