program sprite_editor;

uses
  QForms,
  formMain in 'src\formMain.pas' {frmMain},
  unitAction in 'src\unitAction.pas',
  unitFrame in 'src\unitFrame.pas',
  unitInput in 'src\unitInput.pas',
  unitPoly in 'src\unitPoly.pas',
  unitSprite in 'src\unitSprite.pas',
  unitTrajectory in 'src\unitTrajectory.pas',
  unitTrajPoint in 'src\unitTrajPoint.pas',
  unitTrigger in 'src\unitTrigger.pas',
  formTestAction in 'src\formTestAction.pas' {frmTestAction};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TfrmMain, frmMain);
  Application.CreateForm(TfrmTestAction, frmTestAction);
  Application.Run;
end.
