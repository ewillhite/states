<?php
/**
 * Expose States value(s) as context conditions
 */
class states_context_condition_state extends context_condition {
  // Adds values to context interface and must have a checkbox at least.
  function condition_values() {
    return array(1 => t('Active'));
  }
  // Executes value if event has "State"
  function execute($value) {
    $soldOut = variable_get('states');
    if ($soldOut == 1) {
      foreach ($this->get_contexts($value) as $context) {
        $this->condition_met($context, $value);
      }
    }
  }
}
