#include "KBTracklet.hh"
#ifdef ACTIVATE_EVE
#include "TEveLine.h"
#endif

ClassImp(KBTracklet)

void KBTracklet::AddHit(KBHit *hit)
{
  fHitList -> AddHit(hit);
}

void KBTracklet::RemoveHit(KBHit *hit)
{
  fHitList -> RemoveHit(hit);
}

#ifdef ACTIVATE_EVE
bool KBTracklet::DrawByDefault() { return true; }
bool KBTracklet::IsEveSet() { return false; }

TEveElement *KBTracklet::CreateEveElement()
{
  auto element = new TEveLine();

  return element;
}

void KBTracklet::SetEveElement(TEveElement *element)
{
  auto line = (TEveLine *) element;
  line -> Reset();

  line -> SetLineColor(kRed);

  for (Double_t r = 0.; r < 1.0; r += 0.02) {
    auto pos = ExtrapolateByRatio(r);
    line -> SetNextPoint(pos.X(), pos.Y(), pos.Z());
  }
}

void KBTracklet::AddToEveSet(TEveElement *)
{
}
#endif
