#ifndef R3BNEULANDDIGIMON_H
#define R3BNEULANDDIGIMON_H 1

/** Neuland Digi Monitor
 * @author Jan Mayer
 * @since  10.06.2015
 *
 *  Input:  Digis. Should work both on Digis from Monte Carlo simulations
 *          as well as experimental data on digi level.
 *  Output: Soon: Vairous diagrams.
 *          Currently: A 3D scatterplot for each event.
 */

#include "FairTask.h"

class TClonesArray;
class TH1D;
class TH2D;
class TH3D;

class R3BNeulandDigiMon : public FairTask {
public:
    R3BNeulandDigiMon(const Option_t *option = "");
    ~R3BNeulandDigiMon();

    InitStatus Init();
    void Exec(Option_t *option);
    void Finish();

private:
    TClonesArray *fDigis;

    Bool_t fIs3DTrackEnabled;
    TH3D *fh3;

    TH1D *hDepth;
    TH1D *hForemostEnergy;
    TH1D *hSternmostEnergy;
    TH2D *hDepthVSForemostEnergy;
    TH2D *hDepthVSSternmostEnergy;
    TH1D *hEtot;
    TH2D *hDepthVSEtot;
    TH2D *hPosVSEnergy;

    ClassDef(R3BNeulandDigiMon, 0);
};


#endif //R3BNEULANDDIGIMON_H