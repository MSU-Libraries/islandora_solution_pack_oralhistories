<?php
  unset($transcript_controls['content']['transcript_search']);
  print render($transcript_controls);
?>
<div class="transcript-container">
  <div class="transcript-content" id="transcript">
    <?php print render($transcript); ?>
  </div>
  <div class="itempage-note">Transcripts are an experimental feature and may contain lots of inaccuracies -- <a href="/#disclaimer">find out more</a></div>
</div>
