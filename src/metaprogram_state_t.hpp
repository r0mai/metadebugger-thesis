class metaprogram {
  // ...
public:
  typedef boost::optional<edge_descriptor>
      optional_edge_descriptor;

  typedef std::vector<bool> discovered_t;
  typedef std::vector<optional_edge_descriptor> parent_edge_t;
  typedef std::stack<optional_edge_descriptor> edge_stack_t;

  struct state_t {
    discovered_t discovered;
    parent_edge_t parent_edge;
    edge_stack_t edge_stack;
  };

  void step();
private:
  state_t state;
};
