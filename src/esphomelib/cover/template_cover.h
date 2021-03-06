#ifndef ESPHOMELIB_COVER_TEMPLATE_COVER_H
#define ESPHOMELIB_COVER_TEMPLATE_COVER_H

#include "esphomelib/defines.h"

#ifdef USE_TEMPLATE_COVER

#include "esphomelib/cover/cover.h"
#include "esphomelib/automation.h"

ESPHOMELIB_NAMESPACE_BEGIN

namespace cover {

class TemplateCover : public Cover, public Component {
 public:
  explicit TemplateCover(const std::string &name);

  void set_state_lambda(std::function<optional<CoverState>()> &&f);
  Trigger<NoArg> *get_open_trigger() const;
  Trigger<NoArg> *get_close_trigger() const;
  Trigger<NoArg> *get_stop_trigger() const;
  void set_optimistic(bool optimistic);
  void set_assumed_state(bool assumed_state);

  void loop() override;
  void dump_config() override;

  float get_setup_priority() const override;

 protected:
  void write_command(CoverCommand command) override;
  bool assumed_state() override;

  optional<std::function<optional<CoverState>()>> f_;
  bool assumed_state_{false};
  bool optimistic_{false};
  Trigger<NoArg> *open_trigger_;
  Trigger<NoArg> *close_trigger_;
  Trigger<NoArg> *stop_trigger_;
  Trigger<NoArg> *prev_trigger_{nullptr};
};

} // namespace cover

ESPHOMELIB_NAMESPACE_END

#endif //USE_TEMPLATE_COVER

#endif //ESPHOMELIB_COVER_TEMPLATE_COVER_H
