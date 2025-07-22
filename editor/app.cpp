#include "aerin.h"
#include <printf.h>

class Editor : public Aerin::App {
public:
  Editor() {}
  ~Editor() {}
};

int main() {
  Editor *editor = new Editor();
  editor->Run();
}
