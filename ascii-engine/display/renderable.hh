#include <string>

class Renderable {
public:
  Renderable();
  Renderable(int x, int y, std::string str);

  int get_x() const;
  int get_y() const;
  const std::string& get_str() const;
};
