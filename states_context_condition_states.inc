<?php
/**
 * Expose States value(s) as context conditions
 */
class states_context_condition_states extends context_condition {
  // Adds values to context interface and must have a checkbox at least.
  function condition_values() {
    $states = explode("\n", variable_get('defined_states', ''));
    $values = array();
    foreach ($states as $key => &$value) {
      $values[$key] = $value;
    }
    return $values;
  }
  // Executes value if event has "State"
  function execute($value) {
    dsm($value);
    $states = explode("\n", variable_get('defined_states', ''));
    foreach ($states as $key => &$value) {
      foreach ($this->get_contexts($values) as $context) {
        $state = variable_get('states_' . $key);
        if ($state == 1) {
          $this->condition_met($context);
        }
      }
    }
  }
}
