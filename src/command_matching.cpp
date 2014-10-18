get_command_for_line(string line) {
  command = get_first_word(line);

  // key_command_map is an ordered map of
  // all commands and aliases.
  // key is the command string,
  // value is a pointer to the actual command
  (key, value) = key_command_map.lower_bound(command);

  // no match if the key is greater than the
  // greatest element in key map
  if (key_command_map.past_end(key)) {
    return no_match;
  }

  // No command starts with this prefix
  if (!starts_with(key, command)) {
    return no_match;
  }

  // Check if the found command is unambiguous
  // Pass if the match is full
  if (command != lower->first) {
    for ((next_key, next_value) =
          key_command_map.next(key);
        !key_command_map.past_end(next_key) &&
        starts_with(next_key, command);
        (next_key, next_value) =
          key_command_map.next(next_key))
    {
      // Even if there are multiple matches,
      // aliases for the same command should pass
      // For example forwardtrace and ft with line "f"
      if (next_value != value) {
        return no_match;
      }
    }
  }

  return value;
}
