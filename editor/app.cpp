#include "aerin.h"
#include <printf.h>

class Editor : public Aerin::App {
public:
  Editor() {}
  ~Editor() {}
};

int main() {
  printf("Start editor");
  Editor *editor = new Editor();
  editor->Run();
  delete editor;
}
