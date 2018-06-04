#pragma once

namespace Cheatkey
{
	class ILimitPred;

	class ICommand	// �� �� ȣ�� �� �����Ǵ� Ŀ�ǵ�.
	{
	public:
		explicit ICommand(ILimitPred* p);
		virtual ~ICommand();

		bool operator()(const i3::vector<i3::string>& params);

	private:
		virtual bool _ParseParams(const i3::vector<i3::string>& params) { return true; }
		virtual bool _Execute() { return true; }

		ILimitPred* m_pred;
	};

	class IRunnableCommand	// ���������� ȣ��Ǵ� Ŀ�ǵ�.
	{
	public:
		explicit IRunnableCommand(ILimitPred* p);
		virtual ~IRunnableCommand();

		bool operator()(const REAL32 tm);
		virtual bool ParseParams(const i3::vector<i3::string>& params) { return true; }

	private:
		virtual void _Execute(const REAL32 tm) {}

		ILimitPred* m_pred;
		REAL32 m_tm;
	};
}