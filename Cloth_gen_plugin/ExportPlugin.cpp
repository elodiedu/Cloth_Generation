// Filename: QtPlugin.cpp

#include "stdafx.h"
#include "Qt_file/mainwindow.h"

#include "ExportPlugin.h"
#include "CLOAPIInterface.h"

#include <QApplication>
#include <QTimer>
#include <QMessageBox>
#include <string>
#include <vector>
#include <tuple>
#include <QWidget>

#include <QObject>

using namespace std;
using namespace CLOAPI;

//----------------------------------------------------------------------------------------------------------------------
// Utility functions
//----------------------------------------------------------------------------------------------------------------------
static std::string base64_encode(const std::string& in) {
    std::string out;
    int val = 0, valb = -6;
    for (unsigned char c : in) {
        val = (val << 8) + c;
        valb += 8;
        while (valb >= 0) {
            out.push_back(
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz"
                "0123456789+/"[(val >> valb) & 0x3F]
            );
            valb -= 6;
        }
    }
    if (valb > -6) {
        out.push_back(
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz"
            "0123456789+/"[((val << 8) >> (valb + 8)) & 0x3F]
        );
    }
    while (out.size() % 4) {
        out.push_back('=');
    }
    return out;
}

static std::string getHomePath() {
    // TODO: adapt to other platforms if needed
    return "C:/";
}

//----------------------------------------------------------------------------------------------------------------------
// Sample pattern creation
//----------------------------------------------------------------------------------------------------------------------
extern "C" CLO_PLUGIN_SPECIFIER void CreatePattern_Test(int p1, int p2, int p3,int idx) {
    // Sleeve
    if (idx == 0) {

        int p1t = 2 * p1 - 40;
        vector<tuple<float, float, int>> sleeve_pts = {
            {0.0f, 280.0f, 0},
            {70.0f, 250.0f ,2},
            {90.0f, 200.0f ,2},
            {200.0f, 120.0f, 0},
            {150.0f, 0.0f - p1t, 0},
            {0.0f, 0.0f - p1t, 0},
            {-150.0f, 0.0f - p1t, 0},
                    {-200.0f, 120.0f, 0},
            {-90.0f, 200.0f, 2},
            {-70.0f, 250.0f, 2}

        };
        int p2t = p2 - 60;
        int p3t = p3;
        vector<tuple<float, float, int>> shirt_pts = {
            { 0.0f, 200.0f, 0 }, //The upper inner pos
            { 0.0f, -400.0f - p2t, 0 },
            { -250.0f - p3t, -400.0f - p2t, 0 },
            {-240.0f, 50.0f, 0 }, //The lower sleeve coner
            {-200.0f, 65.0f, 2 },
            {-200.0f, 220.0f, 0 },
            {-100.0f, 260.0f, 0 },
            {-80.0f, 230.0f, 2 } };
        const float dy = 300.0f;
        const float dz = 400.0f;
        const float dxb = 300.0f;
        ///back paterrn
        vector<tuple<float, float, int>> back_pts = {
            {0.0f, 240.0f, 0}, //The upper inner pos
            { 0.0f, -400.0f - p2t, 0 },
            {-250.0f - p3t, -400.0f - p2t, 0 },
            {-240.0f, 50.0f, 0 }, //The lower sleeve coner
            {-200.0f, 65.0f, 2 },
            {-200.0f, 220.0f, 0 },
            {-100.0f, 260.0f, 0 }, //The peak point visible on shoulder
            { -80.0f, 250.0f, 2 }
        };


        vector<tuple<float, float, int>>  mirrored_back;
        mirrored_back.reserve(back_pts.size());



        // Prepare output
        vector<tuple<float, float, int>>  mirrored_sleeve;
        mirrored_sleeve.reserve(sleeve_pts.size());

        vector<tuple<float, float, int>> mirrored_shirt;
        mirrored_shirt.reserve(shirt_pts.size());


        for (const auto& pt : shirt_pts) {
            float x = std::get<0>(pt);
            float y = std::get<1>(pt);
            int   a = std::get<2>(pt);
            mirrored_shirt.push_back({ 2 * dy - x, y, a });
        }
        for (const auto& pt : sleeve_pts) {
            float x = std::get<0>(pt);
            float y = std::get<1>(pt);
            int   a = std::get<2>(pt);
            mirrored_sleeve.push_back({ 2 * dz - x, y, a });
        }
        for (const auto& pt : back_pts) {
            float x = std::get<0>(pt);
            float y = std::get<1>(pt);
            int   a = std::get<2>(pt);
            mirrored_back.push_back({ 2 * dxb - x, y, a });
        }
        // Example output



        int shirt_ = PATTERN_API->CreatePatternWithPoints(shirt_pts);
        int mirrored_shirt_ = PATTERN_API->CreatePatternWithPoints(mirrored_shirt);
        int back_ = PATTERN_API->CreatePatternWithPoints(back_pts);
        int mirrored_back_ = PATTERN_API->CreatePatternWithPoints(mirrored_back);
        int sleeve_ = PATTERN_API->CreatePatternWithPoints(sleeve_pts);
        int mir_sleeve_ = PATTERN_API->CreatePatternWithPoints(mirrored_sleeve);
        PATTERN_API->SetPatternPieceMove(mirrored_shirt_, -600.0, 0.0);
        PATTERN_API->SetPatternPieceMove(back_, 750, 0.0);
        PATTERN_API->SetPatternPieceMove(mirrored_back_, 150, 0.0);
        PATTERN_API->SetPatternPieceMove(sleeve_, -500, 0.0);
        PATTERN_API->SetPatternPieceMove(mir_sleeve_, 500, 0.0);
        PATTERN_API->AddSeamlinePairGroup(
            int(shirt_), // pattern A index
            0, // which segment / line on pattern A
            int(mirrored_shirt_), // pattern B index
            0, // which segment / line on pattern B
            1, // direction on A(True = forward)
            1        //direction on B
        );
        PATTERN_API->AddSeamlinePairGroup(
            int(back_),
            0,
            int(mirrored_back_),
            0,
            1,
            1
        );
        //The shoulder back to front
        PATTERN_API->AddSeamlinePairGroup(
            int(back_),
            4,
            int(mirrored_shirt_),
            4,
            1,
            1
        );
        PATTERN_API->AddSeamlinePairGroup(
            int(mirrored_back_),
            4,
            int(shirt_),
            4,
            1,
            1
        );
        //////back conection
        PATTERN_API->AddSeamlinePairGroup(
            int(back_),
            2,
            int(mirrored_shirt_),
            2,
            1,
            1
        );
        PATTERN_API->AddSeamlinePairGroup(
            int(mirrored_back_),
            2,
            int(shirt_),
            2,
            1,
            1
        );
        ////Sleeves and front
        PATTERN_API->AddSeamlinePairGroup(
            int(sleeve_),
            0,
            int(shirt_),
            3,
            0,
            1
        );
        PATTERN_API->AddSeamlinePairGroup(
            int(mir_sleeve_),
            0,
            int(mirrored_shirt_),
            3,
            0,
            1
        );
        ///Sleeve and back
        PATTERN_API->AddSeamlinePairGroup(
            int(sleeve_),
            5,
            int(mirrored_back_),
            3,
            1,
            1
        );
        PATTERN_API->AddSeamlinePairGroup(
            int(mir_sleeve_),
            5,
            int(back_),
            3,
            1,
            1
        );
        //Sleeve and Sleeve
        PATTERN_API->AddSeamlinePairGroup(
            int(sleeve_),
            1,
            int(sleeve_),
            4,
            1,
            0
        );
        PATTERN_API->AddSeamlinePairGroup(
            int(mir_sleeve_),
            1,
            int(mir_sleeve_),
            4,
            1,
            0
        );
    }
    else if (idx == 1) {
		// The Vneck Shirt in here
        int p1t = 2 * p1 - 40;
        vector<tuple<float, float, int>> sleeve_pts = {
            {0.0f, 280.0f, 0},
            {70.0f, 250.0f ,2},
            {90.0f, 200.0f ,2},
            {200.0f, 120.0f, 0},
            {150.0f, 0.0f - p1t, 0},
            {0.0f, 0.0f - p1t, 0},
            {-150.0f, 0.0f - p1t, 0},
                    {-200.0f, 120.0f, 0},
            {-90.0f, 200.0f, 2},
            {-70.0f, 250.0f, 2}

        };
        int p2t = p2 - 60;
        int p3t = p3;
        vector<tuple<float, float, int>> shirt_pts = {
            { 0.0f, 150.0f, 0 }, //The upper inner pos
            { 0.0f, -400.0f - p2t, 0 },
            { -250.0f - p3t, -400.0f - p2t, 0 },
            {-240.0f, 50.0f, 0 }, //The lower sleeve coner
            {-200.0f, 65.0f, 2 },
            {-200.0f, 220.0f, 0 },
            {-100.0f, 260.0f, 0 },
            {-50.0f, 170.0f, 2 } };
        const float dy = 300.0f;
        const float dz = 400.0f;
        const float dxb = 300.0f;
        ///back paterrn
        vector<tuple<float, float, int>> back_pts = {
            {0.0f, 240.0f, 0}, //The upper inner pos
            { 0.0f, -400.0f - p2t, 0 },
            {-250.0f - p3t, -400.0f - p2t, 0 },
            {-240.0f, 50.0f, 0 }, //The lower sleeve coner
            {-200.0f, 65.0f, 2 },
            {-200.0f, 220.0f, 0 },
            {-100.0f, 260.0f, 0 }, //The peak point visible on shoulder
            { -80.0f, 250.0f, 2 }
        };


        vector<tuple<float, float, int>>  mirrored_back;
        mirrored_back.reserve(back_pts.size());



        // Prepare output
        vector<tuple<float, float, int>>  mirrored_sleeve;
        mirrored_sleeve.reserve(sleeve_pts.size());

        vector<tuple<float, float, int>> mirrored_shirt;
        mirrored_shirt.reserve(shirt_pts.size());


        for (const auto& pt : shirt_pts) {
            float x = std::get<0>(pt);
            float y = std::get<1>(pt);
            int   a = std::get<2>(pt);
            mirrored_shirt.push_back({ 2 * dy - x, y, a });
        }
        for (const auto& pt : sleeve_pts) {
            float x = std::get<0>(pt);
            float y = std::get<1>(pt);
            int   a = std::get<2>(pt);
            mirrored_sleeve.push_back({ 2 * dz - x, y, a });
        }
        for (const auto& pt : back_pts) {
            float x = std::get<0>(pt);
            float y = std::get<1>(pt);
            int   a = std::get<2>(pt);
            mirrored_back.push_back({ 2 * dxb - x, y, a });
        }
        // Example output



        int shirt_ = PATTERN_API->CreatePatternWithPoints(shirt_pts);
        int mirrored_shirt_ = PATTERN_API->CreatePatternWithPoints(mirrored_shirt);
        int back_ = PATTERN_API->CreatePatternWithPoints(back_pts);
        int mirrored_back_ = PATTERN_API->CreatePatternWithPoints(mirrored_back);
        int sleeve_ = PATTERN_API->CreatePatternWithPoints(sleeve_pts);
        int mir_sleeve_ = PATTERN_API->CreatePatternWithPoints(mirrored_sleeve);
        PATTERN_API->SetPatternPieceMove(mirrored_shirt_, -600.0, 0.0);
        PATTERN_API->SetPatternPieceMove(back_, 750, 0.0);
        PATTERN_API->SetPatternPieceMove(mirrored_back_, 150, 0.0);
        PATTERN_API->SetPatternPieceMove(sleeve_, -500, 0.0);
        PATTERN_API->SetPatternPieceMove(mir_sleeve_, 500, 0.0);
        PATTERN_API->AddSeamlinePairGroup(
            int(shirt_), // pattern A index
            0, // which segment / line on pattern A
            int(mirrored_shirt_), // pattern B index
            0, // which segment / line on pattern B
            1, // direction on A(True = forward)
            1        //direction on B
        );
        PATTERN_API->AddSeamlinePairGroup(
            int(back_),
            0,
            int(mirrored_back_),
            0,
            1,
            1
        );
        //The shoulder back to front
        PATTERN_API->AddSeamlinePairGroup(
            int(back_),
            4,
            int(mirrored_shirt_),
            4,
            1,
            1
        );
        PATTERN_API->AddSeamlinePairGroup(
            int(mirrored_back_),
            4,
            int(shirt_),
            4,
            1,
            1
        );
        //////back conection
        PATTERN_API->AddSeamlinePairGroup(
            int(back_),
            2,
            int(mirrored_shirt_),
            2,
            1,
            1
        );
        PATTERN_API->AddSeamlinePairGroup(
            int(mirrored_back_),
            2,
            int(shirt_),
            2,
            1,
            1
        );
        ////Sleeves and front
        PATTERN_API->AddSeamlinePairGroup(
            int(sleeve_),
            0,
            int(shirt_),
            3,
            0,
            1
        );
        PATTERN_API->AddSeamlinePairGroup(
            int(mir_sleeve_),
            0,
            int(mirrored_shirt_),
            3,
            0,
            1
        );
        ///Sleeve and back
        PATTERN_API->AddSeamlinePairGroup(
            int(sleeve_),
            5,
            int(mirrored_back_),
            3,
            1,
            1
        );
        PATTERN_API->AddSeamlinePairGroup(
            int(mir_sleeve_),
            5,
            int(back_),
            3,
            1,
            1
        );
        //Sleeve and Sleeve
        PATTERN_API->AddSeamlinePairGroup(
            int(sleeve_),
            1,
            int(sleeve_),
            4,
            1,
            0
        );
        PATTERN_API->AddSeamlinePairGroup(
            int(mir_sleeve_),
            1,
            int(mir_sleeve_),
            4,
            1,
            0
        );
	}
	else if (idx == 3) {
        //Tank top
        // The Vneck Shirt in here
        int p1t = 2 * p1 - 40;
      
        int p2t = p2 - 60;
        int p3t = p3;
        vector<tuple<float, float, int>> shirt_pts = {
            { 0.0f, 150.0f, 0 }, //The upper inner pos
            { 0.0f, -400.0f - p2t, 0 },//clockwise
            { -250.0f - p3t, -400.0f - p2t, 0 },
            {-180.0f,-200.0f,0},
            {-240.0f, 50.0f, 0 }, //The lower sleeve coner
            {-200.0f, 65.0f, 2 },
            {-140.0f, 250.0f, 0 },
            {-110.0f, 260.0f, 0 },
            {-50.0f, 170.0f, 2 } };
        const float dy = 300.0f;
        const float dz = 400.0f;
        const float dxb = 300.0f;
        ///back paterrn
        vector<tuple<float, float, int>> back_pts = {
            {0.0f, 180.0f, 0}, //The upper inner pos
            { 0.0f, -400.0f - p2t, 0 },
            {-250.0f - p3t, -400.0f - p2t, 0 },
            {-180.0f,-200.0f,0},//The waist 
            {-240.0f, 50.0f, 0 }, //The lower sleeve coner
            {-200.0f, 65.0f, 2 },
            {-140.0f, 250.0f, 0 },
            {-110.0f, 260.0f, 0 }, //The peak point visible on shoulder
            { -80.0f, 200.0f, 2 }
        };


        vector<tuple<float, float, int>>  mirrored_back;
        mirrored_back.reserve(back_pts.size());



        // Prepare output


        vector<tuple<float, float, int>> mirrored_shirt;
        mirrored_shirt.reserve(shirt_pts.size());


        for (const auto& pt : shirt_pts) {
            float x = std::get<0>(pt);
            float y = std::get<1>(pt);
            int   a = std::get<2>(pt);
            mirrored_shirt.push_back({ 2 * dy - x, y, a });
        }
      
        for (const auto& pt : back_pts) {
            float x = std::get<0>(pt);
            float y = std::get<1>(pt);
            int   a = std::get<2>(pt);
            mirrored_back.push_back({ 2 * dxb - x, y, a });
        }
        // Example output



        int shirt_ = PATTERN_API->CreatePatternWithPoints(shirt_pts);
        int mirrored_shirt_ = PATTERN_API->CreatePatternWithPoints(mirrored_shirt);
        int back_ = PATTERN_API->CreatePatternWithPoints(back_pts);
        int mirrored_back_ = PATTERN_API->CreatePatternWithPoints(mirrored_back);
     
        PATTERN_API->SetPatternPieceMove(mirrored_shirt_, -600.0, 0.0);
        PATTERN_API->SetPatternPieceMove(back_, 750, 0.0);
        PATTERN_API->SetPatternPieceMove(mirrored_back_, 150, 0.0);
  
        PATTERN_API->AddSeamlinePairGroup(
            int(shirt_), // pattern A index
            0, // which segment / line on pattern A
            int(mirrored_shirt_), // pattern B index
            0, // which segment / line on pattern B
            1, // direction on A(True = forward)
            1        //direction on B
        );
        PATTERN_API->AddSeamlinePairGroup(
            int(back_),
            0,
            int(mirrored_back_),
            0,
            1,
            1
        );
        //The shoulder back to front
 
        //////back conection
        PATTERN_API->AddSeamlinePairGroup(
            int(back_),
            2,
            int(mirrored_shirt_),
            2,
            1,
            1
        );
        PATTERN_API->AddSeamlinePairGroup(
            int(mirrored_back_),
            2,
            int(shirt_),
            2,
            1,
            1
        );
        //////Add Seamline Group
        PATTERN_API->AddSeamlinePairGroup(
            int(back_),
            3,
            int(mirrored_shirt_),
            3,
            1,
            1
        );
        PATTERN_API->AddSeamlinePairGroup(
            int(mirrored_back_),
           3,
            int(shirt_),
            3,
            1,
            1
        );
        //////Add Seamline Group
        PATTERN_API->AddSeamlinePairGroup(
            int(back_),
            5,
            int(mirrored_shirt_),
            5,
            1,
            1
        );
        PATTERN_API->AddSeamlinePairGroup(
            int(mirrored_back_),
            5,
            int(shirt_),
            5,
            1,
            1
        );


		
    }
    else if (idx == 2) {
        //Hoodie
        int p1t = 2 * p1 - 40;
        vector<tuple<float, float, int>> sleeve_pts = {
            {0.0f, 280.0f, 0},//top
            {70.0f, 250.0f ,2},
            {90.0f, 200.0f ,2},//the left most
            {200.0f, 120.0f, 0},
            {150.0f,-320.0f - p1t, 0},
            {0.0f, -320.0f - p1t, 0},//lower middle
            {-150.0f, -320.0f - p1t, 0},
                    {-200.0f, 120.0f, 0},
            {-90.0f, 200.0f, 2},
            {-70.0f, 250.0f, 2}

        };
        int p2t = p2 - 60;
        int p3t = p3;
        vector<tuple<float, float, int>> shirt_pts = {
            { 0.0f, 200.0f, 0 }, //The upper inner pos
            { 0.0f, -400.0f - p2t, 0 },
            { -250.0f - p3t, -400.0f - p2t, 0 },
            {-240.0f, 50.0f, 0 }, //The lower sleeve coner
            {-200.0f, 65.0f, 2 },
            {-200.0f, 220.0f, 0 },
            {-100.0f, 260.0f, 0 },
            {-80.0f, 230.0f, 2 } };
        const float dy = 300.0f;
        const float dz = 400.0f;
        const float dxb = 300.0f;
        ///back paterrn
        vector<tuple<float, float, int>> back_pts = {
            {0.0f, 240.0f, 0}, //The upper inner pos
            { 0.0f, -400.0f - p2t, 0 },
            {-250.0f - p3t, -400.0f - p2t, 0 },
            {-240.0f, 50.0f, 0 }, //The lower sleeve coner
            {-200.0f, 65.0f, 2 },
            {-200.0f, 220.0f, 0 },
            {-100.0f, 260.0f, 0 }, //The peak point visible on shoulder
            { -80.0f, 250.0f, 2 }
        };
        //the left part of the hoodie
        vector<tuple<float, float, int>> hood_pts = {
          {0.0f, 280.0f, 0}, //The upper inner pos
          { -100.0f,280.0f, 0 },
          {-180.0f, 230.0f, 2 },
          {-200.0f, 150.0f, 0 }, 
          {-200.0f, 0.0f, 0 },//The lower left corner
          {-170.0f, 20.0f, 2 },
          {-100.0f, 30.0f, 0 }, //The peak point visible on shoulder
         
			{0.0f, 30.0f, 0 }
		
			
        };
        vector<tuple<float, float, int>>  mirrored_back;
        mirrored_back.reserve(back_pts.size());



        // Prepare output
        vector<tuple<float, float, int>>  mirrored_sleeve;
        mirrored_sleeve.reserve(sleeve_pts.size());

        vector<tuple<float, float, int>> mirrored_shirt;
        mirrored_shirt.reserve(shirt_pts.size());

        vector<tuple<float, float, int>> mirrored_hood;
        mirrored_hood.reserve(hood_pts.size());


        for (const auto& pt : shirt_pts) {
            float x = std::get<0>(pt);
            float y = std::get<1>(pt);
            int   a = std::get<2>(pt);
            mirrored_shirt.push_back({ 2 * dy - x, y, a });
        }
        for (const auto& pt : sleeve_pts) {
            float x = std::get<0>(pt);
            float y = std::get<1>(pt);
            int   a = std::get<2>(pt);
            mirrored_sleeve.push_back({ 2 * dz - x, y, a });
        }
        for (const auto& pt : back_pts) {
            float x = std::get<0>(pt);
            float y = std::get<1>(pt);
            int   a = std::get<2>(pt);
            mirrored_back.push_back({ 2 * dxb - x, y, a });
		}
        for (const auto& pt : hood_pts) {
            float x = std::get<0>(pt);
            float y = std::get<1>(pt);
            int   a = std::get<2>(pt);
            mirrored_hood.push_back({ 2 * dxb - x, y, a });
        }
        // Example output



        int shirt_ = PATTERN_API->CreatePatternWithPoints(shirt_pts);
        int mirrored_shirt_ = PATTERN_API->CreatePatternWithPoints(mirrored_shirt);
        int back_ = PATTERN_API->CreatePatternWithPoints(back_pts);
        int mirrored_back_ = PATTERN_API->CreatePatternWithPoints(mirrored_back);
        int sleeve_ = PATTERN_API->CreatePatternWithPoints(sleeve_pts);
        int mir_sleeve_ = PATTERN_API->CreatePatternWithPoints(mirrored_sleeve);
        int hood_ = PATTERN_API->CreatePatternWithPoints(hood_pts);
        int mir_hood_ = PATTERN_API->CreatePatternWithPoints(mirrored_hood);
        PATTERN_API->SetPatternPieceMove(mirrored_shirt_, -600.0, 0.0);
        PATTERN_API->SetPatternPieceMove(back_, 750, 0.0);
        PATTERN_API->SetPatternPieceMove(mirrored_back_, 150, 0.0);
        PATTERN_API->SetPatternPieceMove(sleeve_, -500, 0.0);
        PATTERN_API->SetPatternPieceMove(mir_sleeve_, 500, 0.0);
        PATTERN_API->SetPatternPieceMove(hood_,0, 400.0);
        PATTERN_API->SetPatternPieceMove(mir_hood_, 0, 400.0);
        PATTERN_API->AddSeamlinePairGroup(
            int(shirt_), // pattern A index
            0, // which segment / line on pattern A
            int(mirrored_shirt_), // pattern B index
            0, // which segment / line on pattern B
            1, // direction on A(True = forward)
            1        //direction on B
        );
        PATTERN_API->AddSeamlinePairGroup(
            int(back_),
            0,
            int(mirrored_back_),
            0,
            1,
            1
        );
        //The shoulder back to front
        PATTERN_API->AddSeamlinePairGroup(
            int(back_),
            4,
            int(mirrored_shirt_),
            4,
            1,
            1
        );
        PATTERN_API->AddSeamlinePairGroup(
            int(mirrored_back_),
            4,
            int(shirt_),
            4,
            1,
            1
        );
        //////back conection
        PATTERN_API->AddSeamlinePairGroup(
            int(back_),
            2,
            int(mirrored_shirt_),
            2,
            1,
            1
        );
        PATTERN_API->AddSeamlinePairGroup(
            int(mirrored_back_),
            2,
            int(shirt_),
            2,
            1,
            1
        );
        ////Sleeves and front
        PATTERN_API->AddSeamlinePairGroup(
            int(sleeve_),
            0,
            int(shirt_),
            3,
            1,
            0
        );
        PATTERN_API->AddSeamlinePairGroup(
            int(mir_sleeve_),
            0,
            int(mirrored_shirt_),
            3,
            0,
            1
        );
        ///Sleeve and back
        PATTERN_API->AddSeamlinePairGroup(
            int(sleeve_),
            5,
            int(mirrored_back_),
            3,
            1,
            1
        );
        PATTERN_API->AddSeamlinePairGroup(
            int(mir_sleeve_),
            5,
            int(back_),
            3,
            1,
            1
        );
        //Sleeve and Sleeve
        PATTERN_API->AddSeamlinePairGroup(
            int(sleeve_),
            1,
            int(sleeve_),
            4,
            1,
            0
        );
        PATTERN_API->AddSeamlinePairGroup(
            int(mir_sleeve_),
            1,
            int(mir_sleeve_),
            4,
            1,
            0
        );
        ////////Add Seam line group for the left hoodie and left front
		PATTERN_API->AddSeamlinePairGroup(
			int(hood_),
			4,
			int(shirt_),
			5,
			1,
			1
		);
        PATTERN_API->AddSeamlinePairGroup(
            int(hood_),
            3,
            int(mirrored_back_),
            5,
            0,
            1
        );
        PATTERN_API->AddSeamlinePairGroup(
            int(mir_hood_),
            4,
            int(mirrored_shirt_),
            5,
            1,
            1
        );
        PATTERN_API->AddSeamlinePairGroup(
            int(mir_hood_),
            3,
            int(back_),
            5,
            0,
            1
        );
        PATTERN_API->AddSeamlinePairGroup(
            int(mir_hood_),
            2,
            int(hood_),
            2,
            1,
            1
        );
        PATTERN_API->AddSeamlinePairGroup(
            int(mir_hood_),
            1,
            int(hood_),
            1,
            1,
            1
        );
        PATTERN_API->AddSeamlinePairGroup(
            int(mir_hood_),
            0,
            int(hood_),
            0,
            1,
            1
        );

    };



    }


extern "C" CLO_PLUGIN_SPECIFIER void Delete_Clothes(int idx) {

        for (int i = -5; i <= 8; ++i)
        {
            PATTERN_API->DeletePatternPiece(i);
        }
        for (int i = -5; i <= 8; ++i)
        {
            PATTERN_API->DeletePatternPiece(i);
        }
        for (int i = -5; i <= 8; ++i)
        {
            PATTERN_API->DeletePatternPiece(i);
        }
        

 
}
//----------------------------------------------------------------------------------------------------------------------
// Qt UI integration
MainWindow* g_window = nullptr;
extern "C" CLO_PLUGIN_SPECIFIER void showQt()
{       // 1) If there's no QApplication yet, create one.
    if (!QApplication::instance()) {
        static int   fakeArgc = 0;
        static char* fakeArgv[] = { nullptr };
        new QApplication(fakeArgc, fakeArgv);
    }
    if (!g_window) {
        g_window = new MainWindow();
        g_window->setAttribute(Qt::WA_DeleteOnClose);
        g_window->exec();
        g_window = nullptr;
	}
	else {
        g_window->raise();
        g_window->activateWindow();
    }


}

//----------------------------------------------------------------------------------------------------------------------
// Other plugin samples
//----------------------------------------------------------------------------------------------------------------------


void GetInformations_Sample() {
    if (!UTILITY_API) return;
    string fabricInfo = FABRIC_API->GetFabricInfo(0);
    string patternInfo = PATTERN_API->GetPatternInformation(0);
    UTILITY_API->DisplayMessageBox(fabricInfo);
    UTILITY_API->DisplayMessageBox(patternInfo);
}

//----------------------------------------------------------------------------------------------------------------------
// Plugin entry points
//----------------------------------------------------------------------------------------------------------------------
extern "C" CLO_PLUGIN_SPECIFIER void DoFunction() {
    showQt();
 
}


extern "C" CLO_PLUGIN_SPECIFIER const char* GetActionName() {
    return "Rendering Image Sample Plugin";
}
