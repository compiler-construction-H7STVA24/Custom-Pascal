from nltk.tree import Tree

# Read the AST from the syntaxtree.txt file
with open('syntaxtree.txt', 'r') as file:
    text = file.read().strip()

# Replace special characters as per the rules
text = text.replace("(", "ob").replace(")", "cb").replace("[", "(").replace("]", ")")

# Create an NLTK Tree object from the modified text
tree = Tree.fromstring(text)

# Define a function to recursively format the tree for printing
def format_tree(tree, indent=0):
    formatted_text = ""
    if isinstance(tree, Tree):
        formatted_text += " " * indent + tree.label() + "\n"
        for subtree in tree:
            formatted_text += format_tree(subtree, indent + 2)
    else:
        formatted_text += " " * indent + tree + "\n"
    return formatted_text

# Print the formatted tree
print(format_tree(tree))
