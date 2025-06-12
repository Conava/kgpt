#include "SettingsManager.h"
SettingsManager::SettingsManager() : m_cfg("marlon", "kgpt") { load(); }
void SettingsManager::load()
{
    m_aiBackend = m_cfg.value("aiBackend", m_aiBackend).toString();
    m_edge = m_cfg.value("edge", m_edge).toString();
    m_share = m_cfg.value("share", m_share).toDouble();
    m_rounded = m_cfg.value("rounded", m_rounded).toBool();
    m_inset = m_cfg.value("inset", m_inset).toInt();
    m_shortcut = m_cfg.value("shortcut", m_shortcut).toString();
}
void SettingsManager::save()
{
    m_cfg.setValue("aiBackend", m_aiBackend);
    m_cfg.setValue("edge", m_edge);
    m_cfg.setValue("share", m_share);
    m_cfg.setValue("rounded", m_rounded);
    m_cfg.setValue("inset", m_inset);
    m_cfg.setValue("shortcut", m_shortcut);
    emit changed();
}