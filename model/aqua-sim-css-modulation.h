#ifndef AQUA_SIM_CSS_MODULATION_H
#define AQUA_SIM_CSS_MODULATION_H

#include "aqua-sim-modulation.h"

namespace ns3 {

class AquaSimCssModulation : public AquaSimModulation {
public:
  static TypeId GetTypeId();

  AquaSimCssModulation();
  virtual ~AquaSimCssModulation() {}

  double TxTime(int pktSize) override;
  int PktSize(double txTime) override;
  double Per(int pktSize) override;

private:
  double m_spreadingFactor; // Spreading factor for CSS
  double m_bandwidth;       // Bandwidth in Hz
  double m_center_frequency;
};

} // namespace ns3

#endif /* AQUA_SIM_CSS_MODULATION_H */