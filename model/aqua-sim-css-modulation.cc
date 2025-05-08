#include "aqua-sim-css-modulation.h" // Include the corresponding header
#include "ns3/attribute.h"           // For NS-3 attributes
#include "ns3/log.h"                 // For logging
#include <cmath>                     // For std::pow
#include "ns3/double.h"

namespace ns3 {

// Register the CSS modulation class with the NS-3 type system
NS_OBJECT_ENSURE_REGISTERED(AquaSimCssModulation);

TypeId
AquaSimCssModulation::GetTypeId() {
  static TypeId tid = TypeId("ns3::AquaSimCssModulation")
    .SetParent<AquaSimModulation>() // Inherits from AquaSimModulation
    .AddConstructor<AquaSimCssModulation>()
    .AddAttribute("SpreadingFactor", "Spreading factor for CSS modulation.",
                  DoubleValue(7.0), // Default spreading factor
                  MakeDoubleAccessor(&AquaSimCssModulation::m_spreadingFactor),
                  MakeDoubleChecker<double>())
    .AddAttribute("Bandwidth", "Bandwidth in Hz.",
                  DoubleValue(125000), // Default bandwidth in Hz
                  MakeDoubleAccessor(&AquaSimCssModulation::m_bandwidth),
                  MakeDoubleChecker<double>())
    .AddAttribute("CenterFrequency", "Frequency the chrip is centered on",
                  DoubleValue(10000),
                  MakeDoubleAccessor(&AquaSimCssModulation::m_center_frequency),
                  MakeDoubleChecker<double>());
  return tid;
}

AquaSimCssModulation::AquaSimCssModulation()
  : m_spreadingFactor(7.0), m_bandwidth(12500), m_center_frequency(10000) {}

double
AquaSimCssModulation::TxTime(int pktSize) {
  // Compute transmission time for a packet
  return pktSize / (m_bandwidth / std::pow(2, m_spreadingFactor));
}

int
AquaSimCssModulation::PktSize(double txTime) {
  // Compute packet size based on transmission time
  return int(txTime * (m_bandwidth / std::pow(2, m_spreadingFactor)));
}

double
AquaSimCssModulation::Per(int pktSize) {
  // Example packet error rate calculation
  return 1 - std::pow(1 - m_ber, pktSize);
}

} // namespace ns3