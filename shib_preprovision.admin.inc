<?php

/**
 * @file
 */

/**
 * shib_preprovision settings form.
 */
function shib_preprovision_admin_settings() {
  $form = array();

  $form['shib_provision'] = array(
    '#type' => 'fieldset',
    '#title' => t('Account pre-creation'),
    '#collapsible' => FALSE,
  );

  $form['shib_provision']['shib_preprovision_account'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Automatically add SSO user account entries to the authmap and shib_authmap tables.'),
    '#description'   => t('If checked, account usernames that match a regular expression will be treated as SSO accounts. Enabling this option will automatically add matching account entries to the authmap and shib_authmap tables on user account creation / update, skipping the manual process listed in the module documentation. Please read !url for more information.', array('!url' => l(t('the technical documentation page for the shib_auth module'), "https://wiki.niif.hu/index.php?title=DrupalShibbolethReadmeDev#Pre-creating_users"))),
    '#default_value' => variable_get('shib_preprovision_account', FALSE),
  );

  $form['shib_provision']['shib_preprovision_username_regex'] = array(
    '#type'          => 'textfield',
    '#title'         => t('SSO usernames regular expression'),
    '#description'   => t('Accounts with usernames that match this regular expression will be treated as SSO accounts. Example: for usernames ending in "@example.com", use "/@example\.com$/".'),
    '#default_value' => variable_get('shib_preprovision_username_regex', ''),
    '#states' => array(
      'visible' => array(
        ':input[name="shib_preprovision_account"]' => array('checked' => TRUE),
      ),
    ),
  );

  return system_settings_form($form);
}
