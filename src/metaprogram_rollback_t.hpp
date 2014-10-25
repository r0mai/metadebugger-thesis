class metaprogram {
  // ...
public:
  struct step_rollback_t {
    optional_edge_descriptor popped_edge;
    optional_vertex_descriptor discovered_vertex;
    unsigned edge_stack_push_count = 0;
    boost::optional<optional_edge_descriptor> set_parent_edge;
  };

  typedef std::stack<step_rollback_t> state_history_t;
private:
  state_history_t state_history;
};
