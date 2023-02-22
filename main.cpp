#include "gif.hpp"

const int width = 128;
const int height = 128;

int main() {
  const std::string filename{"./output.gif"};
  gif::GifWriter writer{filename, width, height, 2};

  int i = rand() % 128, j = rand() % 128;
  int i_speed = -1;
  int j_speed = 2;
  for (int frame_number = 0; frame_number < 1000; ++frame_number) {

    // write current position if gif
    gif::Frame frame{width, height};
    frame[{i, j}] = gif::Pixel{(255), (255), (255)};
    writer.write_frame(frame);
    
    // update position and speed
    i += i_speed;
    j += j_speed;

    if (i > height - 1) {
      i = height - 1;
      i_speed = -i_speed;
    }
    if (i <= 1) {
      i = 1;
      i_speed = -i_speed;
    }
    if (j > height - 1) {
      j = height - 1;
      j_speed = -j_speed;
    }
    if (j <= 1) {
      j = 1;
      j_speed = -j_speed;
    }
  }
  
  return 0;
}
