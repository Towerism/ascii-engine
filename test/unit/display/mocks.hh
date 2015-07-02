#include <gmock/gmock.h>
#include <string>
#include <vector>
#include <ascii-engine/render/renderer.hh>
#include <terminal.hh>

class Mock_renderer : public Renderer {
public:
  MOCK_METHOD1(add, void(Renderable*));
  MOCK_METHOD0(render, std::vector<std::string>());
  MOCK_CONST_METHOD0(get_width, int());
  MOCK_CONST_METHOD0(get_height, int());
  MOCK_CONST_METHOD1(get_renderable, Renderable*(int));
};

class Mock_terminal : public Terminal {
public:
  MOCK_METHOD1(print, void(std::string));
  MOCK_METHOD0(refresh, void());
  MOCK_METHOD0(hard_refresh, void());
  MOCK_METHOD0(clear, void());
};
