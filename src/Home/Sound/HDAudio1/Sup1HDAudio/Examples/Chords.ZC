U0 Chords(Bool val=ON)
{
  if (snd_dev!=SD_HD_AUDIO) {
    "Only works for HD Audio.\n";
    return;
  }
  HDTonesInit;
  if (val) {
    hda.tone_swcs[1]->freq_multiplier=4.0/3.0;
    hda.tone_swcs[1]->amp_multiplier=1.0;
    hda.tone_swcs[2]->freq_multiplier=(4.0/3.0)`2;
    hda.tone_swcs[2]->amp_multiplier=1.0;
  }
}

Chords(ON);
