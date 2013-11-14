<?php
/**
 * Expose States value(s) as context conditions
 */
class states_context_condition_states extends context_condition {
  // Adds values to context interface and must have a checkbox at least.
  function condition_values() {
    $values = array();
    $states = preg_split('/[\r\n]+/', variable_get('defined_states', ''), -1, PREG_SPLIT_NO_EMPTY);
    foreach ($states as $key => $setstate) {
      $state_var = strtolower(str_replace(" ","_",$setstate));
      $values[$state_var] = check_plain($setstate);
    }
    return $values;
  }
  // Executes value if event has "State"
  function execute() {
    $states = preg_split('/[\r\n]+/', variable_get('defined_states', ''), -1, PREG_SPLIT_NO_EMPTY);
    foreach ($this->get_contexts() as $context) {
      dsm($context);
      foreach ($states as $key => &$value) {
        $state = variable_get('states_' . $key);
        if ($state == 1) {
          $this->condition_met($context, $value);
        }
      }
    }
  }
}
