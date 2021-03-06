<?php

/**
 * @file
 * Handles the display/submission of the admin settings form for this module.
 */

/**
 * Defines the admin settings form.
 *
 * @param array $form
 *   The Drupal form definition.
 * @param array $form_state
 *   The Drupal form state.
 *
 * @return array
 *   The Drupal form definition.
 */
function islandora_oralhistories_admin(array $form, array &$form_state) {
  module_load_include('inc', 'islandora', 'includes/solution_packs');
  $form = array();
  // Get viewer table.
//  $viewer_table = islandora_viewers_form('islandora_oralhistories_viewers', 'video/mp4');
//  $form += $viewer_table;

  $form['islandora_oralhistories_make_vtt'] = array(
    '#type' => 'checkbox',
    '#title' => t('Create WEBVTT file for captions or subtitles.'),
    '#description' => t('Will create WEBVTT file from transcript xml file based on "transcript" tier.'),
    '#default_value' => variable_get('islandora_oralhistories_make_vtt', FALSE),
  );

  $form['islandora_oralhistories_enable_caption_display'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable captions/subtitles display'),
    '#description' => t('Display captions or subtitles on video player when WEBVTT file exists.'),
    '#default_value' => variable_get('islandora_oralhistories_enable_caption_display', FALSE),
  );
  $form['islandora_oralhistories_enbable_transcript_display'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable transcript display'),
    '#description' => t('Display transcript synchronously with the video or audio.'),
    '#default_value' => variable_get('islandora_oralhistories_enbable_transcript_display', FALSE),
  );

  $form['islandora_oralhistories_transcript_layout_side'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display media and transcript side-by-side'),
    '#description' => t('By default, the trascript will be displayed beneath the media object.'),
    '#default_value' => variable_get('islandora_oralhistories_transcript_layout_side', FALSE),
  );

  $form['islandora_oralhistories_annotation_tab_display'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display annotation tab'),
    '#description' => t('By default, the annotation tab will not be displayed.'),
    '#default_value' => variable_get('islandora_oralhistories_annotation_tab_display', FALSE),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset to defaults'),
    '#weight' => 1,
    '#submit' => array('islandora_oralhistories_admin_reset'),
  );

  $form = system_settings_form($form);
  return $form;

}

/**
 * Form reset for allowing the deletion of the viewer variable.
 */
function islandora_oralhistories_admin_reset($form, &$form_state) {
  $op = $form_state['clicked_button']['#id'];
  switch ($op) {
    case 'edit-reset':
      variable_del('islandora_oralhistories_make_vtt');
      variable_del('islandora_oralhistories_enable_caption_display');
      variable_del('islandora_oralhistories_enbable_transcript_display');
      variable_del('islandora_oralhistories_transcripts_viewer_tiers');
      variable_del('islandora_oralhistories_transcript_layout_side');
      break;
  }

}
