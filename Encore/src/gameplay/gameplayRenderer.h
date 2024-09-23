#pragma once
//
// Created by marie on 09/06/2024.
//

#include <utility>
#include "users/player.h"
#include "song/song.h"

class gameplayRenderer {
    void RenderNotes(
        Player *player,
        Chart &curChart,
        double time,
        RenderTexture2D &notes_tex,
        float length
    );
    void RenderHud(Player *player, RenderTexture2D &, float);
    void RenderExpertHighway(
        Player *player,
        Song song,
        double time,
        RenderTexture2D &highway_tex,
        RenderTexture2D &highwayStatus_tex,
        RenderTexture2D &smasher_tex
    );
    void RenderPDrumsHighway(
        Player *player,
        Song song,
        double time,
        RenderTexture2D &highway_tex,
        RenderTexture2D &highwayStatus_tex,
        RenderTexture2D &smasher_tex
    );
    void DrawHighwayMesh(
        float LengthMultiplier, bool Overdrive, float ActiveTime, float SongTime
    );

    void
    RenderEmhHighway(Player *player, Song song, double time, RenderTexture2D &highway_tex);
    void DrawBeatlines(Player *player, Song *song, float length, double musicTime);
    void DrawOverdrive(Player *player, Chart &curChart, float length, double musicTime);
    void DrawSolo(Player *player, Chart &curChart, float length, double musicTime);

    void DrawFill(Player *player, Chart &curChart, float length, double musicTime);

    void RenderClassicNotes(
        Player *player,
        Chart &curChart,
        double time,
        RenderTexture2D &notes_tex,
        float length
    );
    void RenderPDrumsNotes(
        Player *player,
        Chart &curChart,
        double time,
        RenderTexture2D &notes_tex,
        float length
    );

    void nDrawDrumsHitEffects(Note note, double time, float notePosX);
    void nDrawFiveLaneHitEffects(Note note, double time, float notePosX);
    void
    nDrawPlasticNote(Note note, Color noteColor, float notePosX, float noteScrollPos);
    void nDrawPadNote(Note note, Color noteColor, float notePosX, float noteScrollPos);
    void nDrawSustain(Note note, Color noteColor, float notePosX, Matrix sustainMatrix);

    void eDrawSides(
        float scrollPos,
        double time,
        double start,
        double end,
        float length,
        double radius,
        Color color
    );

    double GetNoteOnScreenTime(
        double noteTime, double songTime, float noteSpeed, int Difficulty, float length
    );
    double HighwaySpeedDifficultyMultiplier(int Difficulty);
    float MaxHighwaySpeed = 1.25f;
    float MinHighwaySpeed = 0.5f;

public:
    float highwayLevel = 0;
    float smasherPos = 2.4f;
    float HitAnimDuration = 0.15f;
    bool highwayInAnimation = false;
    bool highwayInEndAnim = false;
    bool highwayOutAnimation = false;
    bool highwayOutEndAnim = false;
    float animDuration = 1.0f;
    bool overstrum = false;
    int selectedSongInt = 0;
    bool songPlaying = false;
    bool showHitwindow = false;

    bool extendedSustainActive = false;
    float textureOffset = 0;
    float renderPos = 0;
    int cameraSel = 0;
    Mesh sustainPlane;
    Mesh soloPlane;
    std::vector<std::vector<Camera3D> > cameraVectors;
    std::vector<Camera3D> camera1pVector;
    std::vector<Camera3D> camera2pVector;
    std::vector<Camera3D> camera3pVector;
    std::vector<Camera3D> camera4pVector;

    Camera3D camera1p = { 0 };

    Camera3D camera2p1 = { 0 };
    Camera3D camera2p2 = { 0 };

    Camera3D camera3p1 = { 0 };
    Camera3D camera3p2 = { 0 };
    Camera3D camera3p3 = { 0 };

    Camera3D camera4p1 = { 0 };
    Camera3D camera4p2 = { 0 };
    Camera3D camera4p3 = { 0 };
    Camera3D camera4p4 = { 0 };

    /*
    gpr.camera.position = Vector3{ 0.0f, 7.0f, -10.0f };
    // 0.0f, 0.0f, 6.5f
    gpr.camera.target = Vector3{ 0.0f, 0.0f, 13.0f };
     */

    void
    RenderGameplay(Player *player, double time, Song song, RenderTexture2D &, RenderTexture2D &, RenderTexture2D &, RenderTexture2D &, RenderTexture2D &);

    bool upStrum = false;
    bool downStrum = false;
    bool FAS = false;
    bool processingStrum = false;

    void RaiseHighway();

    void LowerHighway();

    void NoteMultiplierEffect(double time, double hitTime, bool miss, Player *player);
    double multiplierEffectTime = 1.0;
};
