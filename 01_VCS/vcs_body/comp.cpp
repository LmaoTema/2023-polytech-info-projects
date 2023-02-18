#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

struct RepositoryState {
  std::map<std::string, int> files;

  RepositoryState() {}

  RepositoryState(const std::vector<std::pair<std::string, int>>& fileList) {
    for (const auto& file : fileList) {
      files[file.first] = file.second;
    }
  }

  std::vector<std::string> Compare(const RepositoryState& other) const {
    std::vector<std::string> changes;

    for (const auto& file : files) {
      const auto it = other.files.find(file.first);
      if (it == other.files.end()) {
        changes.push_back("File " + file.first + " only exists in state 1");
      } else if (it->second != file.second) {
        changes.push_back("File " + file.first + " has different size in state 1 and state 2");
      }
    }

    for (const auto& file : other.files) {
      if (files.find(file.first) == files.end()) {
        changes.push_back("File " + file.first + " only exists in state 2");
      }
    }

    return changes;
  }
};

int main() {
  RepositoryState state1({{"file1.txt", 100}, {"file2.txt", 200}});
  RepositoryState state2({{"file2.txt", 200}, {"file3.txt", 300}});

  std::vector<std::string> changes = state1.Compare(state2);

  std::cout << "Changes between state 1 and state 2:\n";
  for (const auto& change : changes) {
    std::cout << change << '\n';
  }

  return 0;
}
