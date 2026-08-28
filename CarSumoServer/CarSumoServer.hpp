enum ECarControlType
{
	ESCT_Human,
	ESCT_AI
};

class CarSumoServer : public CarSumo
{
public:
	static GameObjectPtr	StaticCreate() { return NetworkManagerServer::sInstance->RegisterAndReturn(new CarSumoServer()); }
	virtual void HandleDying() override;

	virtual void Update() override;

	void SetCarControlType(ECarControlType inCarControlType) { mCarControlType = inCarControlType; }

	void TakeDamage(int inDamagingPlayerId);

protected:
	CarSumoServer();

private:

	ECarControlType	mCarControlType;

};

