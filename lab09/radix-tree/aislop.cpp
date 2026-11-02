#include <algorithm>
#include <map>
#include <string>

class RadixTree {
private:
    struct Node {
        std::map<char, Node*> children;
        std::string edge;  // The label of the edge leading to this node
        bool is_end;

        Node(const std::string& e = "", bool end = false) : edge(e), is_end(end) {}

        ~Node() {
            for (auto& pair : children) {
                delete pair.second;
            }
        }
    };

    Node* root;

    // Helper to find the common prefix length of two strings
    static size_t commonPrefixLength(const std::string& a, const std::string& b) {
        size_t len = std::min(a.length(), b.length());
        size_t i = 0;
        while (i < len && a[i] == b[i]) {
            i++;
        }
        return i;
    }

public:
    RadixTree() { root = new Node(); }

    ~RadixTree() { delete root; }

    // Insert a word into the Radix Tree
    void insert(const std::string& word) {
        Node* curr = root;
        std::string remaining = word;

        while (!remaining.empty()) {
            char first_char = remaining[0];

            // Case 1: No child exists with this starting character
            if (curr->children.find(first_char) == curr->children.end()) {
                curr->children[first_char] = new Node(remaining, true);
                return;
            }

            Node* child = curr->children[first_char];
            size_t common = commonPrefixLength(child->edge, remaining);
            // the edge is leading to this node and not

            if (common == child->edge.length()) {
                // Case 2: The edge is a complete prefix of remaining
                remaining = remaining.substr(common);
                if (remaining.empty()) {
                    child->is_end = true;
                    return;
                }
                curr = child;
            } else {
                // Case 3: Partial match -> We need to split the edge
                std::string common_str = child->edge.substr(0, common);
                std::string child_remainder = child->edge.substr(common);
                std::string word_remainder = remaining.substr(common);

                // Create intermediate node
                Node* mid_node = new Node(common_str, false);

                // Adjust existing child and reattach
                child->edge = child_remainder;
                mid_node->children[child_remainder[0]] = child;

                // Add new child if there is remaining word part
                if (word_remainder.empty()) {
                    mid_node->is_end = true;
                } else {
                    Node* new_child = new Node(word_remainder, true);
                    mid_node->children[word_remainder[0]] = new_child;
                }

                // Replace child pointer in current node
                curr->children[first_char] = mid_node;
                return;
            }
        }
    }

    // Search for an exact word in the Radix Tree
    bool search(const std::string& word) const {
        Node* curr = root;
        std::string remaining = word;

        while (!remaining.empty()) {
            char first_char = remaining[0];
            if (curr->children.find(first_char) == curr->children.end()) {
                return false;
            }

            Node* child = curr->children[first_char];
            if (remaining.length() < child->edge.length()) {
                return false;
            }

            if (remaining.substr(0, child->edge.length()) != child->edge) {
                return false;
            }

            remaining = remaining.substr(child->edge.length());
            curr = child;
        }

        return curr->is_end;
    }

    // Check if any word starts with the given prefix
    bool startsWith(const std::string& prefix) const {
        Node* curr = root;
        std::string remaining = prefix;

        while (!remaining.empty()) {
            char first_char = remaining[0];
            if (curr->children.find(first_char) == curr->children.end()) {
                return false;
            }

            Node* child = curr->children[first_char];
            size_t len = std::min(remaining.length(), child->edge.length());

            if (remaining.substr(0, len) != child->edge.substr(0, len)) {
                return false;
            }

            if (remaining.length() <= child->edge.length()) {
                return true;  // Prefix matched entirely within this edge
            }

            remaining = remaining.substr(child->edge.length());
            curr = child;
        }

        return true;
    }
};
nt main(int argc, char** argv) {}
