#ifndef UNISPARKS_EFFECT_FLAME_H
#define UNISPARKS_EFFECT_FLAME_H
#include "unisparks/effects/functional.hpp"
namespace unisparks {

class Flame : public Effect {
  size_t contextSize(const Animation& a) const override;
  void begin(const Frame& frame) const override;
  void rewind(const Frame& f) const override;
  Color color(const Pixel& px) const override;
};

inline Flame flame() {
  return Flame();
}

} // namespace unisparks
#endif /* UNISPARKS_EFFECT_FLAME_H */
