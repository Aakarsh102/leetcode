class Trie {
    Set<String> k;
    private class Node {
        boolean isWord=false;
        Node[] children = new Node[26];
        public Node() {}
    }
    Node root = new Node();
    public Trie() {}
    
    public void insert(String word) {
        Node cur = root;
        for (char i : word.toCharArray()) {
            if (cur.children[i - 'a'] == null) {
                cur.children[i - 'a'] = new Node();
            }
            cur = cur.children[i - 'a'];
        }
        cur.isWord = true;
    }
    
    public boolean search(String word) {
        Node cur = root;
        for (char i : word.toCharArray()) {
            if (cur.children[i - 'a'] == null) {
                return false;
            }
            cur = cur.children[i - 'a'];
        }
        return cur.isWord;
    }
    
    public boolean startsWith(String prefix) {
        Node cur = root;
        for (char i : prefix.toCharArray()) {
            if (cur.children[i - 'a'] == null) {
                return false;
            }
            cur = cur.children[i - 'a'];
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */