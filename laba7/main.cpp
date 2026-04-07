#include "iostream"
#include "string"
#include "vector"

class FileSystemNode {
public:
    virtual void display() = 0;
    virtual int getSize() = 0;
    virtual bool isDirectory() = 0;
    virtual ~FileSystemNode() = default;
};

class File: public FileSystemNode {
private:
    int fSize;
    std::string fName;
public:
    File(int size, std::string name) : fSize(size), fName(name) {}

    void display() override {
        std::cout << "Файл: " << fName << "Размер: " << fSize << std::endl;
    };
    int getSize() override { return fSize; }

    bool isDirectory() override { return false; }

    void open() {
        std::cout << "Открыт файл: " << fName << std::endl;
    }
};

class Directory: public FileSystemNode {
private:
    std::string dirName;
    std::vector<FileSystemNode*> children;
public:
    Directory(std::string name) : dirName(name) {}

    ~Directory() {
        for (FileSystemNode* child : children) {
            delete child;
        }
    }

    int getSize() override {
        int sum = 0;
        for (FileSystemNode* child : children) {
            sum += child->getSize();
        }
        return sum;
    }
    void display() override {
        std::cout << dirName << "/\n";
        for (FileSystemNode* child : children) {
            std::cout << "\t";
            child->display();
        }
    }
    bool isDirectory() override { return true; }

    void addNode(FileSystemNode* node) {
        children.push_back(node);
    }
};

int main() {

    Directory* root = new Directory("root");
    Directory* documents = new Directory("documents");
    Directory* photos = new Directory("photos");
    File* file1 = new File(3, "text.txt");
    File* file2 = new File(4, "new_text.txt");
    File* file3 = new File(6, "music.mp3");
    File* file4 = new File(10, "photo.png");

    root->addNode(documents);
    root->addNode(photos);
    root->addNode(file3);

    documents->addNode(file1);
    documents->addNode(file2);

    photos->addNode(file4);

    root->display();

    std::cout << "Общий размер корневой папки: " << root->getSize() << std::endl;

    delete root;
    return 0;
}